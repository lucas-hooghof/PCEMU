#pragma once

#include <CPU/Registers/Register.h>

typedef struct 
{
    Register A;
    Register B;
    Register C;
    Register D;
    Register DI;
    Register SI;

    //ONLY ACCESSABLE IN 64-bit MODE
    Register R8;
    Register R9;
    Register R10;
    Register R11;
    Register R12;
    Register R13;
    Register R14;
    Register R15;

    //SEGMENT REGISTERS
    uint16_t cs;
    uint16_t ds;
    uint16_t fs;
    uint16_t ss;
    uint16_t es;
    uint16_t gs;

    //NO 8-BIT VERSIONS
    Register InstructionPointer;
    Register StackPointer;
    Register BasePointer;

}CPU;