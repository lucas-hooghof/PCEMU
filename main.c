#include <stdio.h>
#include <core/PrintingErrors.h>
#include <Memory/Memory.h>
#include <CPU/IO/IOPorts.h>
#include <CPU/Stack/Stack.h>
#include <CPU/cpu.h>

#include <Hardware/VirtualSerial.h>

int main(int argc,char* argv[])
{
    InitilizeMemory(1024*1024);
    InitilizeSerial();

    CPU cpu;
    InitlizeCPU(&cpu,CPU_16_BIT);
    uint64_t emulatedaddress = cpu.cs << 4;
    emulatedaddress += 0xFFF0;
    uint64_t trueAddress = EMULATOR_TO_REAL(emulatedaddress);
    uint8_t* memory = (uint8_t*)trueAddress;
    *memory = 0xF4;
    while (true)
    {
        if (cpu.halt)
        {
            continue;
        }

        FetchInstruction(&cpu);
    }
    DeinitilizeMemory();
    return 0;
}