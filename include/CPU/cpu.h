#pragma once

#include <CPU/Registers/Register.h>

#define FLAG_CF   (1U << 0)   // Carry Flag
#define FLAG_PF   (1U << 2)   // Parity Flag
#define FLAG_AF   (1U << 4)   // Auxiliary Carry
#define FLAG_ZF   (1U << 6)   // Zero Flag
#define FLAG_SF   (1U << 7)   // Sign Flag
#define FLAG_TF   (1U << 8)   // Trap Flag
#define FLAG_IF   (1U << 9)   // Interrupt Enable
#define FLAG_DF   (1U << 10)  // Direction Flag
#define FLAG_OF   (1U << 11)  // Overflow Flag
#define FLAG_IOPL (3U << 12)  // IOPL is 2 bits (bits 12-13)
#define FLAG_NT   (1U << 14)  // Nested Task
#define FLAG_RF   (1U << 16)  // Resume Flag
#define FLAG_VM   (1U << 17)  // Virtual-8086 Mode
#define FLAG_AC   (1U << 18)  // Alignment Check
#define FLAG_VIF  (1U << 19)  // Virtual Interrupt Flag
#define FLAG_VIP  (1U << 20)  // Virtual Interrupt Pending
#define FLAG_ID   (1U << 21)  // ID Flag

#define FLAG_SET(flags, flag)    ((flags) |= (flag))
#define FLAG_CLEAR(flags, flag)  ((flags) &= ~(flag))
#define FLAG_TOGGLE(flags, flag) ((flags) ^= (flag))
#define FLAG_CHECK(flags, flag)  (((flags) & (flag)) != 0)

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

    //Control Registers
    uint64_t CR0;
    uint64_t CR2;
    uint64_t CR3;
    uint64_t CR4;
    uint64_t CR8;

    //EXTRA
    uint8_t Mode; // 1 is 16-bit 2 32-bit protected mode 4 is 64-bit long mode

    uint32_t flags;
}CPU;



