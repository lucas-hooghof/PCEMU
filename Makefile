CFLAGS=-Wall -fsanitize=address -I include/ -DLINUX
SRC := $(shell find src -name '*.c')
CC=gcc


CompileMainI386: build/
	$(CC) -o build/PCEMU main.c $(SRC) Arch/i386/*.c $(CFLAGS) 

build/:
	mkdir build