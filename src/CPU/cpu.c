#include <CPU/cpu.h>

#include <CPU/Opcodes.h>
#include <core/PrintingErrors.h>
//Private
uint64_t GetAddress(CPU* cpu,uint64_t address,uint16_t SegmentValue)
{
    uint64_t addr = 0;
    if (cpu->CurrentMode == CPU_16_BIT)
    {
        addr = SegmentValue << 4; //Same as times 16 but i think is faster
        addr += address;
    }
    else {
        addr = address;
    }

    return addr;
}

//Public
void InitlizeCPU(CPU* cpu,uint8_t mode)
{
    cpu->MaxMode = mode;
    cpu->CurrentMode = CPU_16_BIT;
    SetValueInRegister(&cpu->BasePointer,XREG,0x8000);
    SetValueInRegister(&cpu->StackPointer,XREG,0x8000);

    SetValueInRegister(&cpu->InstructionPointer,XREG,0xFFF0);
    cpu->cs = 0xFFFF;
}

void FetchInstruction(CPU* cpu)
{
    uint64_t instructionAddress = 0;
    if (cpu->CurrentMode == CPU_16_BIT)
    {
        uint16_t Address = GetValueInRegister(&cpu->InstructionPointer,XREG);
        instructionAddress = GetAddress(cpu,Address,cpu->cs);
        SetValueInRegister(&cpu->InstructionPointer,XREG,Address+1);
    }

    uint8_t OpcodeByte = GetByteFromMemory(instructionAddress);
}