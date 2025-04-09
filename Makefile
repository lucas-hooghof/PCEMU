CFLAGS=-Wall -fsanitize=address -I include/

CC=gcc
CompileMain: build/
	$(CC) -o build/PCEMU main.c $(CFLAGS) 

build/:
	mkdir build