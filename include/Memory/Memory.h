#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/mman.h>

#include <core/PrintingErrors.h>

extern void* AllotedMemory;
extern uint64_t MemoryAddress;
extern size_t SizeOfMemory;

#define EMULATOR_TO_REAL(EmulatedAddress) (MemoryAddress + EmulatedAddress)

bool InitilizeMemory(size_t size);
void DeinitilizeMemory();

void WriteDataIntoMemory(void* memory,uint64_t Emulatedaddress,size_t size);
void* ReadDataFromMemory(uint64_t Emulatedaddress, size_t size);