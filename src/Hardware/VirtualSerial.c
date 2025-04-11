#include <Hardware/VirtualSerial.h>

void PrintCharacterToSerial(uint16_t port,uint32_t value,int state,uint32_t* optionalOutPut)
{
    putc(value & 0xFF,stdout);
}

void InitilizeSerial()
{
    RegisterPort(0xE9,PrintCharacterToSerial);
}