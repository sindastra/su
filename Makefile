CC ?= gcc

all: su

su: su.c
	$(CC) $(CFLAGS) su.c -o su
