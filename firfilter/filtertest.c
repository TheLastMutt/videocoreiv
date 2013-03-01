// This file is based on mailbox.c found on
// https://github.com/hermanhermitage/videocoreiv/wiki/VideoCore-IV-Kernels-under-Linux

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/ioctl.h>		/* ioctl */
#include "vcio.h"

#define PAGE_SIZE (4*1024)

static void *mapmem(unsigned base, unsigned size)
{
   int mem_fd;
   unsigned offset = base % PAGE_SIZE; 
   base = base - offset;
   /* open /dev/mem */
   if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0) {
      printf("can't open /dev/mem \n");
      exit (-1);
   }
   void *mem = mmap(
      0,
      size,
      PROT_READ|PROT_WRITE,
      MAP_SHARED/*|MAP_FIXED*/,
      mem_fd, 
      base);
#ifdef DEBUG
   printf("base=0x%x, mem=%p\n", base, mem);
#endif
   if (mem == MAP_FAILED) {
      printf("mmap error %d\n", (int)mem);
      exit (-1);
   }
   close(mem_fd);
   return (char *)mem + offset;
}

static void unmapmem(void *addr, unsigned size)
{
   int s = munmap(addr, size);
   if (s != 0) {
      printf("munmap error %d\n", s);
      exit (-1);
   }
}

/* 
 * use ioctl to send mbox property message
 */

static int mbox_property(int file_desc, void *buf)
{
   int ret_val = ioctl(file_desc, IOCTL_MBOX_PROPERTY, buf);

   if (ret_val < 0) {
      printf("ioctl_set_msg failed:%d\n", ret_val);
   }

#ifdef DEBUG
   unsigned *p = message; int i; unsigned size = *(unsigned *)buf;
   for (i=0; i<size/4; i++)
      printf("%04x: 0x%08x\n", i*sizeof *p, p[i]);
#endif
   return ret_val;
}

static unsigned get_version(int file_desc)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x00000001; // get firmware version
   p[i++] = 0x00000004; // buffer size
   p[i++] = 0x00000000; // request size
   p[i++] = 0x00000000; // value buffer

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

unsigned mem_alloc(int file_desc, unsigned size, unsigned align, unsigned flags)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x3000c; // (the tag id)
   p[i++] = 12; // (size of the buffer)
   p[i++] = 12; // (size of the data)
   p[i++] = size; // (num bytes? or pages?)
   p[i++] = align; // (alignment)
   p[i++] = flags; // (MEM_FLAG_L1_NONALLOCATING)

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

unsigned mem_free(int file_desc, unsigned handle)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x3000f; // (the tag id)
   p[i++] = 4; // (size of the buffer)
   p[i++] = 4; // (size of the data)
   p[i++] = handle;

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

unsigned mem_lock(int file_desc, unsigned handle)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x3000d; // (the tag id)
   p[i++] = 4; // (size of the buffer)
   p[i++] = 4; // (size of the data)
   p[i++] = handle;

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

unsigned mem_unlock(int file_desc, unsigned handle)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x3000e; // (the tag id)
   p[i++] = 4; // (size of the buffer)
   p[i++] = 4; // (size of the data)
   p[i++] = handle;

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

unsigned execute_code(int file_desc, unsigned code, unsigned r0, unsigned r1, unsigned r2, unsigned r3, unsigned r4, unsigned r5)
{
   int i=0;
   unsigned p[32];
   p[i++] = 0; // size
   p[i++] = 0x00000000; // process request

   p[i++] = 0x30010; // (the tag id)
   p[i++] = 28; // (size of the buffer)
   p[i++] = 28; // (size of the data)
   p[i++] = code;
   p[i++] = r0;
   p[i++] = r1;
   p[i++] = r2;
   p[i++] = r3;
   p[i++] = r4;
   p[i++] = r5;

   p[i++] = 0x00000000; // end tag
   p[0] = i*sizeof *p; // actual size

   mbox_property(file_desc, p);
   return p[5];
}

static void dumpBuffer(int16_t * buffer, uint32_t size)
{
  uint32_t i; 
  for (i=0; i<size; i++)
  {
    printf("%04hx ", buffer[i]);
    if((i%16)==15)
      printf("\n");
  }
}

// Usage of the 4 buffers
#define CODE 2
#define OUTPUT 3
#define INPUT 0
#define TAPS 1

// Sizes in bytes
#define INPUT_SIZE (1024*1024*6)
#define TAPS_SIZE (128 * 2)
#define CODE_SIZE (1024)
#define OUTPUT_SIZE INPUT_SIZE

// Don't call filter at all
#define TEST_WITHOUT_FILTER (0)
// 1 megasamples
#define TEST_1M (1024*1024)
// 2 megasamples
#define TEST_2M (1024*1024*2)
// 3 megasamples
#define TEST_3M (1024*1024*3)

#define TEST_SMALL (32)

// Test to perform
#define TEST_CASE TEST_3M

/* 
 * Main - Call the ioctl functions 
 */
int main(int argc, char *argv[])
{
   int file_desc;
   unsigned int i;
  int16_t *user_s16p;
   unsigned handle[4], buffer[4];
   void *user[4];
   

   // open a char device file used for communicating with kernel mbox driver
   file_desc = open(DEVICE_FILE_NAME, 0);
   if (file_desc < 0) {
      printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
      printf("Try creating a device file with: mknod %s c %d 0\n", DEVICE_FILE_NAME, MAJOR_NUM);
      exit(-1);
   }
   // sanity check we care talking to GPU - should match vcgencmd version
   printf("Version: %d\n", get_version(file_desc));


   handle[INPUT] = mem_alloc(file_desc, INPUT_SIZE, 4096, 0xc);
   buffer[INPUT] = mem_lock(file_desc, handle[INPUT]);
   printf("handle=%x, buffer=%x\n", handle[INPUT], buffer[INPUT]);
   user[INPUT] = mapmem(buffer[INPUT], INPUT_SIZE);

   handle[TAPS] = mem_alloc(file_desc, TAPS_SIZE, 4096, 0xc);
   buffer[TAPS] = mem_lock(file_desc, handle[TAPS]);
   printf("handle=%x, buffer=%x\n", handle[TAPS], buffer[TAPS]);
   user[TAPS] = mapmem(buffer[TAPS], TAPS_SIZE);

   handle[CODE] = mem_alloc(file_desc, CODE_SIZE, 4096, 0xc);
   buffer[CODE] = mem_lock(file_desc, handle[CODE]);
   printf("handle=%x, buffer=%x\n", handle[CODE], buffer[CODE]);
   user[CODE] = mapmem(buffer[CODE], CODE_SIZE);

   handle[OUTPUT] = mem_alloc(file_desc, OUTPUT_SIZE, 4096, 0xc);
   buffer[OUTPUT] = mem_lock(file_desc, handle[OUTPUT]);
   printf("handle=%x, buffer=%x\n", handle[OUTPUT], buffer[OUTPUT]);
   user[OUTPUT] = mapmem(buffer[OUTPUT], OUTPUT_SIZE);

   // Initialize code buffer
   memset(user[CODE], 0x00, CODE_SIZE);
   
   // Output buffer
   user_s16p = (int16_t *)user[OUTPUT];
   // 15 zeroes and one nonzero entry are needed by the GPU code
   // to initialize flags
   for(i=0;i<15;i++)
   {
     user_s16p[i] = 0x0000;
   }
   user_s16p[i] = 0xFFFF;
   
   // Source data 1 (filter input)
   // If full filter output is desired (for seamless concatenation
   // of data chunks) pad source data with zeroes at the end as needed
   user_s16p = (int16_t *)user[INPUT];
   for(i=0;i<(INPUT_SIZE/2)-100;i++)
   {
     user_s16p[i] = 0x1000;
   }
   //user_s16p[0] = 0xFF80;
   
   // Source data 2 (filter taps)
   // If you have less than 128 taps then pad them
   // with zeroes at the start of the array.
   // The last value in the TAPS array will be multiplied with
   // the newest sample.
   memset(user[TAPS], 0x00, TAPS_SIZE);
   user_s16p = (int16_t *)user[TAPS];
   
   // Just some test stuff
   for(i=60;i<124;i++)
   {
     user_s16p[i] = 4;
   }

   printf("Input\n");
   dumpBuffer((int16_t *)user[INPUT], 128);
   printf("Taps\n");
   dumpBuffer((int16_t *)user[TAPS], 128);
//   printf("Dest\n");
//   dumpBuffer((int16_t *)user[DEST], 64);
      
   // load GPU code into one of the buffers.
   FILE *fp = fopen("firfilter.bin", "rb");
   assert(fp);
   fread(user[CODE], 1, CODE_SIZE, fp);
   fclose(fp);
   
   printf("Execute\n");
#if TEST_CASE != TEST_WITHOUT_FILTER
   // execute the GPU code:        code          r0              r1            r2           r3   r4       r5
   (void)execute_code(file_desc, buffer[CODE], buffer[OUTPUT], buffer[INPUT], buffer[TAPS], 0,  TEST_CASE, 0);
#endif
   printf("Output start\n");
   dumpBuffer((int16_t *)user[OUTPUT], 256);
#if TEST_CASE != TEST_WITHOUT_FILTER
   printf("Output end\n");
   dumpBuffer(((int16_t *)user[OUTPUT])+TEST_CASE-256, 256);
#endif

   // free up (important - if you don't call mem_free that memory will be lost for good)
  munmap(user[INPUT], INPUT_SIZE);
  mem_unlock(file_desc, handle[INPUT]);
  mem_free(file_desc, handle[INPUT]);
  munmap(user[TAPS], TAPS_SIZE);
  mem_unlock(file_desc, handle[TAPS]);
  mem_free(file_desc, handle[TAPS]);
  munmap(user[CODE], CODE_SIZE);
  mem_unlock(file_desc, handle[CODE]);
  mem_free(file_desc, handle[CODE]);
  munmap(user[OUTPUT], OUTPUT_SIZE);
  mem_unlock(file_desc, handle[OUTPUT]);
  mem_free(file_desc, handle[OUTPUT]);

  close(file_desc);
  return 0;
}
