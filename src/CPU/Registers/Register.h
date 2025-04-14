#include <CPU/Registers/Register.h>

void SetValueInRegister(Register* reg,REG registerpart,uint64_t value)
{
    switch(registerpart)
    {
        case RREG:
        {
            reg->rreg = value;
            reg->ereg = reg->rreg & 0x00000000FFFFFFFF;
            reg->xreg = reg->ereg & 0x0000FFFF;
            reg->hreg = reg->xreg & 0xFF00;
            reg->lreg = reg->xreg & 0x00FF;
        }break;

        case EREG:
        {
            reg->ereg = value & 0x00000000FFFFFFFF;
            reg->xreg = reg->ereg & 0x0000FFFF;
            reg->hreg = reg->xreg & 0xFF00;
            reg->lreg = reg->xreg & 0x00FF;
            reg->rreg = (reg->rreg & 0xFFFFFFFF00000000) | (uint64_t)reg->ereg; 
        }break;

        case XREG:
        {
            reg->xreg = value & 0x000000000000FFFF;
            reg->hreg = reg->xreg & 0xFF00;
            reg->lreg = reg->lreg & 0x00FF;
            reg->ereg = (reg->ereg & 0xFFFF0000) | (uint32_t)reg->xreg;
            reg->rreg = (reg->rreg & 0xFFFFFFFF00000000) | (uint64_t)reg->ereg; 
        }break;

        case HREG:
        {
            reg->hreg = value & 0x000000000000FF00;
            reg->xreg = (reg->xreg & 0x00FF) | (uint8_t)(reg->hreg << 8);
            reg->ereg = (reg->ereg & 0xFFFF0000) | (uint32_t)reg->xreg;
            reg->rreg = (reg->rreg & 0xFFFFFFFF00000000) | (uint64_t)reg->ereg;
        }break;

        case LREG:
        {
            reg->lreg = value & 0x00000000000000FF;
            reg->xreg = (reg->xreg & 0xFF00) | (uint8_t)reg->lreg;
            reg->ereg = (reg->ereg & 0xFFFF0000) | (uint32_t)reg->xreg;
            reg->rreg = (reg->rreg & 0xFFFFFFFF00000000) | (uint64_t)reg->ereg;

        }break;
    }
}

uint64_t GetValueInRegister(Register* reg,REG registerpart)
{
    switch(registerpart)
    {
        case RREG:
        {
            return (uint64_t)reg->rreg;
        }break;

        case EREG:
        {
            return (uint64_t)reg->ereg;
        }break;

        case XREG:
        {
            return (uint64_t)reg->xreg;
        }break;

        case HREG:
        {
            return (uint64_t)reg->hreg;
        }break;

        case LREG:
        {
            return (uint64_t)reg->lreg;
        }break;
    }

    return 0;
}