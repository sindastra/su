CC ?= gcc

all: su

su: su.c
	$(CC) -static -O3 $(CFLAGS) su.c -o su
