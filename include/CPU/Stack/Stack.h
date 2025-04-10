#pragma once

#include <stdint.h>
#include <Memory/Memory.h>

void Push8(uint64_t* StackAddress,uint8_t value);
void Push16(uint64_t* StackAddress,uint16_t value);
void Push32(uint64_t* StackAddress,uint32_t value);
void Push64(uint64_t* StackAddress,uint64_t value);

uint8_t Pop8(uint64_t*  StackAddress);
uint16_t Pop16(uint64_t* StackAddress);
uint32_t Pop32(uint64_t* StackAddress);
uint64_t Pop64(uint64_t* StackAddress);

