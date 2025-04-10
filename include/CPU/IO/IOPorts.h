#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef void (*PortHandler)(uint16_t port,uint32_t value,int state,uint32_t* optionalOutPut);

#define IO_OUTPUT_8_STATE   1
#define IO_OUTPUT_16_STATE  2
#define IO_OUTPUT_32_STATE  3
#define IO_INPUT_8_STATE    4 
#define IO_INPUT_16_STATE   5
#define IO_INPUT_32_STATE   6

typedef struct 
{  
    PortHandler handler;
    uint32_t output;
}Port;

extern Port PortTable[UINT16_MAX];

Port IO_LookupPort(uint16_t Index);
void IO_OutputToPort8(uint16_t PortIndex, uint8_t value);
void IO_OutputToPort16(uint16_t PortIndex, uint16_t value);
void IO_OutputToPort32(uint16_t PortIndex, uint32_t value);
uint8_t IO_InputFromPort8(uint16_t PortIndex);
uint16_t IO_InputFromPort16(uint16_t PortIndex);
uint32_t IO_InputFromPort32(uint16_t PortIndex);

bool IsPortValid(uint16_t PortIndex);
void RegisterPort(uint16_t PortIndex, PortHandler handler);