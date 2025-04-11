#pragma once

#include <stdio.h>
#include <stdint.h>

#include <CPU/IO/IOPorts.h>

void PrintCharacterToSerial(uint16_t port,uint32_t value,int state,uint32_t* optionalOutPut);

void InitilizeSerial();