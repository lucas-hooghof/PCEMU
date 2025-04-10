#include <CPU/IO/IOPorts.h>

#include <core/PrintingErrors.h>

Port PortTable[UINT16_MAX] = {0};

Port IO_LookupPort(uint16_t Index)
{
    if (IsPortValid(Index))
    {
        PRINT_ERROR_TAG("IO","Handle not defined:");
        printf("\tHandle: %u\n",Index);
        exit(EXIT_FAILURE);
    }

    return PortTable[Index];
}
void IO_OutputToPort8(uint16_t PortIndex, uint8_t value)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,(uint32_t)value,IO_OUTPUT_8_STATE,NULL);
}

void IO_OutputToPort16(uint16_t PortIndex, uint16_t value)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,(uint32_t)value,IO_OUTPUT_16_STATE,NULL);
}
void IO_OutputToPort32(uint16_t PortIndex, uint32_t value)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,value,IO_OUTPUT_32_STATE,NULL);
}
uint8_t IO_InputFromPort8(uint16_t PortIndex)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,0,IO_INPUT_8_STATE,&port.output);

    return (uint8_t)port.output;
}
uint16_t IO_InputFromPort16(uint16_t PortIndex)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,0,IO_INPUT_16_STATE,&port.output);

    return (uint16_t)port.output;
}
uint32_t IO_InputFromPort32(uint16_t PortIndex)
{
    Port port = IO_LookupPort(PortIndex);
    port.handler(PortIndex,0,IO_INPUT_32_STATE,&port.output);

    return (uint32_t)port.output;
}

bool IsPortValid(uint16_t PortIndex)
{
    return PortTable[PortIndex].handler == NULL;
}
void RegisterPort(uint16_t PortIndex, PortHandler handler)
{
    PortTable[PortIndex].handler = handler;
}