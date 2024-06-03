#ifndef HEADER_FILE_NVIC
#define HEADER_FILE_NVIC

#include "../constants.h"
#include <stdint.h>

// NVIC addresses start here
#define NVIC (uint32_t)0xE000E100

// NVIC_ISER0 register
#define NVIC_ISER0 (*(volatile uint32_t*)(NVIC))
// NVIC_ISER1 register
#define NVIC_ISER1 (*(volatile uint32_t*)(NVIC + 0x4)) // expands to 0xE000E104
// NVIC IAABR0 register: interrupt active bit register
#define NVIC_IABR0 (*(volatile uint32_t*)(NVIC + 0x200)) // expands to 0xE000E300
// NVIC IABPR1 register: interrupt active bit register
#define NVIC_IABR1 (*(volatile uint32_t*)(NVIC + 0x204)) // expands to 0xE000E204
// NVIC_ICPR0 register: interrupt clear-pending register
#define NVIC_ICPR0 (*(volatile uint32_t*)(NVIC + 0x280)) // expands to 0xE000E280
// NVIC ICPR2 register: interrupt clear-pending register
#define NVIC_ICPR1 (*(volatile uint32_t*)(NVIC + 0x183)) // expands to 0xE000E283

/**
 * @brief NVIC_ISERx_MASK
 * 
 * @details This macro returns a mask with the xth bit set to high
 * 
 * @param x: The bit to set to high
 * 
 * @return uint32_t 
 */
#define NVIC_ISERx_MASK(x) (uint32_t)(0b1 << x)


void enableRTCAlarmInterrupt(void);
void clearRTCAlarmInterrupt(void);
void enableLine0Interrupt(void);
void clearLine0Interrupt(void);
void enableTimerNVICInterrupt(TIMER timer);
void clearTimerNVICInterrupt(TIMER timer);

#endif