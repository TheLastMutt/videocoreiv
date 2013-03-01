//
// This work is covered by the following variation of the WTFPL:
//
//             DO WHAT YOU WANT TO PUBLIC LICENSE
//                     Version 1, December 2012
//
//  Copyright (C) 2012 The contributors.
//
//  Everyone is permitted to copy and distribute verbatim or modified
//  copies of this license document, and changing it is allowed as long
//  as the name is changed.
//
//             DO WHAT YOU WANT TO PUBLIC LICENSE
//    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
//
//   0. You just DO WHAT YOU WANT TO.
//

// Uncomment this to use the 16 bit accumulators included in every pixel processing unit.
// This is faster but I am not sure if this works in every case
#define FAST

// Configuration for 128 taps
// If this is changed the source code below has to be changed, too.
// See comment "Repeat this until DATAROW-1 is reached"
// DATAROW * 16 = 128 taps
#define REPCOUNT (REP8)
#define DATAROW  (8)
// Not tested yet:
// Values can be changed to 1, 2, 4, 8 and 16
// to get 16, 32, 64, 128 or 256 taps.
// A value of 32 can only be used when "FAST" is not defined and DATAROW is 31.
// This gives 496 taps. More is not possible because there is not enough space
// for the filter taps anymore. Such a long filter should probably better be
// implemented using FFT anyway.
 

  START("firfilter.bin");
  
  // execute the GPU code:           code          r0              r1             r2            r3 r4       r5
  // int s = execute_code(file_desc, buffer[CODE], buffer[OUTPUT], buffer[INPUT], buffer[TAPS], 0, samples, 0);
  // r0 = &output
  // r1 = &input
  // r2 = &taps
  // r3 is result accumulator (low words)
  // r4 = number of samples to calculate, must be multiple of 16
  // r5 used for temporary storage
  // r6 is result accumulator (high words)
  // r7 is loop counter
  
  // Labels
  declare(loop16samples);
  declare(outerLoop);

  // Push r6 and r7.
  // r6 is result accumulator
  // r7 is loop counter
  push_r6_rn(1);
  
  // Multiply number of samples by 2 to get number of bytes
  lsli(r4, 1);
  // Calculate destination end pointer
  add(r4, r0);
  
  movi(r5, 0x0020);
  // Clear delay buffer with zeroes
  vi80(v_mov, HXy0, 0, INC, HXy0, 0, INC, 0, REPCOUNT);
  // Load filter taps
  vld80(W16, HXy0, 32, INC, 0, r2, r5, REPCOUNT);
  // Load 16 words from destination buffer: 15 zeroes and last value not zero.
  // This is used to clear zero flag only on last PPU.
  vld80(W16, HXy0, DATAROW, NOINC, 0, r0, r5, REP1);
  // add #0 does nothing,  just set flags and then don't touch them again
  vi80acc(v_add, HXy0, DATAROW, NOINC, HXy0, 0, DATAROW, NOINC, 0, REP1, vc_all, SETF, NOACC);

label(outerLoop);
  // Load first/next chunk of data (16 samples)
  // r5 is just placeholder because we don't use increment
  vld80(W16, HXy0, DATAROW, NOINC, 0, r1, r5, REP1);
  
  // Clear loop counter
  movi(r7, 0);
  
label(loop16samples);
  // Rotate all delay buffer rows and the input data row to the left.
  // First element will then be last.
  // Can't use v_mov because we need source cell PX(y,1)
  // PX(y, x) = PX(y,(x+1)%16)
  // To get wrap-around we need to use HY access, which destroys data in HX(0,32) to HX(DATAROW, 32).
  // This does not care.

  // delay buffer
  vi80acc(v_add, HYy0, 0, INC, HYy0, 1, 0, INC, 0, REPCOUNT, vc_all, KEEPF, NOACC);
  // incoming data
  vi80acc(v_add, HYy0, DATAROW, NOINC, HYy0, 1, DATAROW, NOINC, 0, REP1, vc_all, KEEPF, NOACC);

  // Move 16th column one element up
  // vc_ifnz makes sure that only the last value will be moved,
  vr80c(v_mov, HXy0, 0, INC, HXy0, 0, INC, HXy0, 1, INC, REPCOUNT, vc_ifnz);
  
  // **************************
  // Sum high words of multiplication
  // results in r6
  // **************************

#ifdef FAST

  // Faster, but intermediate results might overflow.
  // ADDACCSAT saturates intermediate results to 0x7FFF.
  // ADDACC doesn't.
  // Adding with overflow might work because an overflow should be
  // temporary. Filter taps usually sum up to 0 or 1.
  // If filter gain is greater than 1 the saturation might be useful??
  // v_mulhd_ss: signed multiply, high result
  vr80acc(v_mulhd_ss, HXy32, 0, INC, HXy0, 0, 0, INC, HXy0, 32, INC, REPCOUNT, vc_all, KEEPF, (ADDACC|CLRA|UPDACC));
  vi80sru(v_add, HXy32, (DATAROW-1), NOINC, HXy32, 0, (DATAROW-1), NOINC, 0, REP1, vc_all, KEEPF, sru_sum, r6);
  
#else
  
  // A bit slower but uses 32 bit accumulator which does not overflow
  // Clear accumulator register
  movi(r6, 0);
  // Signed multiply, add all 16 multiplication results, treat as signed
  // Store high result to HX(32, 0) (not even needed)
  //                  destination      input data         filter taps
  vr80sru(v_mulhd_ss, HXy32, 0, NOINC, HXy0, 0, 0, NOINC, HXy0, 32, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  // Repeat this until DATAROW-1 is reached
  vr80sru(v_mulhd_ss, HXy32, 1, NOINC, HXy0, 0, 1, NOINC, HXy0, 33, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 2, NOINC, HXy0, 0, 2, NOINC, HXy0, 34, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 3, NOINC, HXy0, 0, 3, NOINC, HXy0, 35, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 4, NOINC, HXy0, 0, 4, NOINC, HXy0, 36, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 5, NOINC, HXy0, 0, 5, NOINC, HXy0, 37, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 6, NOINC, HXy0, 0, 6, NOINC, HXy0, 38, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
  vr80sru(v_mulhd_ss, HXy32, 7, NOINC, HXy0, 0, 7, NOINC, HXy0, 39, INC, REP1, vc_all, KEEPF, sru_sum, r5);
  add(r6, r5);
#endif

  // **************************
  // Sum low words of multiplication
  // results in r3
  // **************************
  
  // Here we cannot use the fast version because the overflow is essential.
  
  // Clear accumulator register
  movi(r3, 0);
  // Signed multiply, add all 16 multiplication results, treat as unsigned
  // Here we need unsigned sums to put the results together with the high word results
  // Store high result to HX(32, 0) (not even needed)
  //             destination      input data         filter taps
  vr80sru(v_mul, HXy32, 0, NOINC, HXy0, 0, 0, NOINC, HXy0, 32, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  // Repeat this until DATAROW-1 is reached
  vr80sru(v_mul, HXy32, 1, NOINC, HXy0, 0, 1, NOINC, HXy0, 33, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 2, NOINC, HXy0, 0, 2, NOINC, HXy0, 34, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 3, NOINC, HXy0, 0, 3, NOINC, HXy0, 35, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 4, NOINC, HXy0, 0, 4, NOINC, HXy0, 36, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 5, NOINC, HXy0, 0, 5, NOINC, HXy0, 37, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 6, NOINC, HXy0, 0, 6, NOINC, HXy0, 38, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  vr80sru(v_mul, HXy32, 7, NOINC, HXy0, 0, 7, NOINC, HXy0, 39, INC, REP1, vc_all, KEEPF, sru_sumu, r5);
  add(r3, r5);
  
  // Put both results together (32 bit)
  lsli(r6, 16);
  add(r6, r3);

  // shift result right to get correct Q15*Q15 result into low word
  asri(r6, 15);
  
  // Store r6 at *dest, low word only
  st_w_rd_rs_inc(w_h, r6, r0);
  
  // rd += 1;  if (rd != 16) then branch
  addcmpb_c_rd_i_u_o(c_ne, r7, 1, 16, loop16samples);
  
  // increment source data pointer by 16 words
  addi(r1, 32);
  // enough samples calculated?
  cmp(r0, r4);
  blo(outerLoop);

  // Pop r6 and r7
  pop_r6_rn(1);
  rts();

  END
