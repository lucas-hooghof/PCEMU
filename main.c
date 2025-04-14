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
    while (true)
    {
        if (cpu.halt)
        {
            continue;
        }

        
    }
    DeinitilizeMemory();
    return 0;
}