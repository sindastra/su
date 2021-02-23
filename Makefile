CC ?= gcc

all: su

su: su.c
	$(CC) -O3 $(CFLAGS) su.c -o su
