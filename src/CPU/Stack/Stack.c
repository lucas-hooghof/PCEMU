#include <CPU/Stack/Stack.h>

void Push8(uint64_t* StackAddress, uint8_t value)
{
    (*StackAddress)--;
    uint8_t* stackmemory = (uint8_t*)((*StackAddress)+(MemoryAddress));
    *stackmemory = value;
}
void Push16(uint64_t* StackAddress, uint16_t value)
{
    Push8(StackAddress, (value >> 8) & 0xFF); // MSB
    Push8(StackAddress, (value >> 0) & 0xFF); // LSB
}

void Push32(uint64_t* StackAddress, uint32_t value)
{
    Push8(StackAddress, (value >> 24) & 0xFF); // MSB
    Push8(StackAddress, (value >> 16) & 0xFF);
    Push8(StackAddress, (value >> 8) & 0xFF);
    Push8(StackAddress, (value >> 0) & 0xFF);  // LSB
}

void Push64(uint64_t* StackAddress, uint64_t value)
{
    Push8(StackAddress, (value >> 56) & 0xFF); // MSB
    Push8(StackAddress, (value >> 48) & 0xFF);
    Push8(StackAddress, (value >> 40) & 0xFF);
    Push8(StackAddress, (value >> 32) & 0xFF);
    Push8(StackAddress, (value >> 24) & 0xFF);
    Push8(StackAddress, (value >> 16) & 0xFF);
    Push8(StackAddress, (value >> 8) & 0xFF);
    Push8(StackAddress, (value >> 0) & 0xFF);  // LSB
}

uint8_t Pop8(uint64_t* StackAddress)
{
    uint8_t* memory = (uint8_t*)((*StackAddress)+(MemoryAddress));
    uint8_t value = *memory;
    (*StackAddress)++;
    return value;
}

uint16_t Pop16(uint64_t* StackAddress)
{
    uint16_t b0 = Pop8(StackAddress);
    uint16_t b1 = Pop8(StackAddress);
    return (b1 << 8) | b0;
}

uint32_t Pop32(uint64_t* StackAddress)
{
    uint32_t b0 = Pop8(StackAddress);
    uint32_t b1 = Pop8(StackAddress);
    uint32_t b2 = Pop8(StackAddress);
    uint32_t b3 = Pop8(StackAddress);
    return (b3 << 24) | (b2 << 16) | (b1 << 8) | b0;
}

uint64_t Pop64(uint64_t* StackAddress)
{
    uint64_t b0 = Pop8(StackAddress);
    uint64_t b1 = Pop8(StackAddress);
    uint64_t b2 = Pop8(StackAddress);
    uint64_t b3 = Pop8(StackAddress);
    uint64_t b4 = Pop8(StackAddress);
    uint64_t b5 = Pop8(StackAddress);
    uint64_t b6 = Pop8(StackAddress);
    uint64_t b7 = Pop8(StackAddress);
    return ((uint64_t)b7 << 56) | ((uint64_t)b6 << 48) | ((uint64_t)b5 << 40) | ((uint64_t)b4 << 32) |
           ((uint64_t)b3 << 24) | ((uint64_t)b2 << 16) | ((uint64_t)b1 << 8) | b0;
}
