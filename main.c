#include <stdio.h>
#include <core/PrintingErrors.h>
#include <Memory/Memory.h>
#include <CPU/IO/IOPorts.h>
#include <CPU/Stack/Stack.h>

int main(int argc,char* argv[])
{
    InitilizeMemory(1024*1024);
    uint64_t addr = 0x0000000000007c00;
    Push64(&addr,10);
    printf("Popped value: %d\n",Pop64(&addr));
    DeinitilizeMemory();
    return 0;
}