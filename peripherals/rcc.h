#ifndef HEADER_FILE_RCC
#define HEADER_FILE_RCC

#include "../constants.h"
#include <stdint.h>

// Reset and Clock Control registers
#define RCC (PERIPHERAL + 0x21000) // expands to 0x40021000

// RCC_APB1 peripheral clock enable register
#define RCC_APB1ENR (*(volatile uint32_t*)(RCC + 0x1C)) // expands to 0x4002101C
// RCC APB2 peripheral clock enable register
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC + 0x18)) // expands to 0x40021018
// RCC_BDCR register
#define RCC_BDCR (*(volatile uint32_t*)(RCC + 0x20)) // expands to 0x40021020
// RCC_CFGR register
#define RCC_CFGR (*(volatile uint32_t*)(RCC + 0x04)) // expands to 0x40021004


void openPortCClockGate(void);
void setupRCCForRTC(void);
int getRCCBDCRLSERDY(void);
void openPortBClockGate(void);
void enableTimerClock(TIMER timer);
void setAPB1Prescaler(int prescaler);
void setAHBPrescaler(int prescaler);

#endif