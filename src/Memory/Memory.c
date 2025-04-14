#include <Memory/Memory.h>

void* AllotedMemory;
uint64_t MemoryAddress;
size_t SizeOfMemory;

bool InitilizeMemory(size_t size)
{
    #ifdef LINUX
        AllotedMemory = mmap(NULL,size,PROT_WRITE | PROT_READ,MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        if (AllotedMemory == NULL)
        {
            PRINT_ERROR_TAG("Memory","Failed to Allocated Memory");
            return false;
        }
    #endif
    SizeOfMemory = size;
    MemoryAddress = (uint64_t)(AllotedMemory);

    return true;
}


void DeinitilizeMemory()
{
    #ifdef LINUX
        munmap(AllotedMemory,SizeOfMemory);
    #endif
}

void WriteDataIntoMemory(void* memory,uint64_t Emulatedaddress,size_t size)
{
    if (Emulatedaddress > SizeOfMemory)
    {
        PRINT_ERROR_TAG("MEMORY","Tried to write into non existent memory");
        exit(EXIT_FAILURE);
    }

    uint8_t* memoryptr =(uint8_t*)EMULATOR_TO_REAL(Emulatedaddress);
    uint8_t* srcptr = (uint8_t*)memory;
    for (size_t i = 0; i < size; i++)
    {
        memoryptr[i] = srcptr[i];
    }
}

void* ReadDataFromMemory(uint64_t Emulatedaddress, size_t size)
{
    if (Emulatedaddress > SizeOfMemory)
    {
        PRINT_ERROR_TAG("MEMORY","Tried to read from non existent memory");
        exit(EXIT_FAILURE);
    }

    void* memory = (void*)EMULATOR_TO_REAL(Emulatedaddress);
    return memory;
}

uint8_t GetByteFromMemory(uint64_t EmulatedAddress)
{
    uint8_t* mem = (uint8_t*)AllotedMemory+EmulatedAddress;

    return *mem;
}
uint16_t GetWordFromMemory(uint64_t EmulatedAddress)
{
    uint8_t* base = (uint8_t*)AllotedMemory + EmulatedAddress;
    return base[0] | (base[1] << 8);  
}