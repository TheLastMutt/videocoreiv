vctest: filtertest.c firfilter.s build.c ../tinyasm/asm.c ../tinyasm/videocoreiv.h
	gcc build.c -o build
	./build
	gcc -Wall -o filtertest filtertest.c

clean:
	rm firfilter.bin build filtertest
