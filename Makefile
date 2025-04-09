CFLAGS=-Wall -fsanitize=address -I include/ -DLINUX
SRC := $(shell find src -name '*.c')
CC=gcc
CompileMain: build/
	$(CC) -o build/PCEMU main.c $(SRC) $(CFLAGS) 

build/:
	mkdir build