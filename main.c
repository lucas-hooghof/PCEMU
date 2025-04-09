#include <stdio.h>
#include <core/PrintingErrors.h>
#include <Memory/Memory.h>


int main(int argc,char* argv[])
{
    InitilizeMemory(1024*1024);

    DeinitilizeMemory();
    return 0;
}