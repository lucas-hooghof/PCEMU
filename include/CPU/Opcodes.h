#pragma once

#define PREFIX_16_BIT           0x66
#define PREFIX_32_BIT           0x67

#define PREFIX_LOCK             0xF0

#define OPCODE_HALT             0xF4

#define OPCODE_IN_AL            0xE4
#define OPCODE_IN_AX            0xE5
#define OPCODE_IN_EAX           0xE5
#define OPCODE_IN_AL_DX         0xEC
#define OPCODE_IN_AX_DX         0xED
#define OPCODE_IN_EAX_DX        0xED