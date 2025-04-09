#pragma once

#include <stdint.h>

//Register
// RAX -> 8 bytes
    // EAX -> 4 bytes
        // AX -> 2 bytes
            // AH,AL -> 1 byte

typedef struct
{
    uint64_t rreg;
    uint32_t ereg;
    uint16_t xreg;
    uint8_t hreg; // High byte of xregister
    uint8_t lreg; // Low byte of xregister
}Register;

typedef enum
{
    RREG,
    EREG,
    XREG,
    HREG,
    LREG
}REG;

void SetValueInRegister(Register* reg,REG registerpart,uint64_t value);