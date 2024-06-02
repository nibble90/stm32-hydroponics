#ifndef HEADER_FILE_EXTI
#define HEADER_FILE_EXTI

#include "../constants.h"
#include <stdint.h>
#include "tim.h"

// EXTI addresses start here
#define EXTI (PERIPHERAL + 0x10400)
// EXTI_IMR register: interrupt mask register
#define EXTI_IMR (*(volatile uint32_t*)(EXTI))
// EXTI_EMR register: event mask register
#define EXTI_EMR (*(volatile uint32_t*)(EXTI + 0x4)) // expands to 0x40010404
// EXTI_RTSR register: rising trigger selection register
#define EXTI_RTSR (*(volatile uint32_t*)(EXTI + 0x8)) // expands to 0x40010408
// EXTI_FTSR register: falling trigger selection register
#define EXTI_FTSR (*(volatile uint32_t*)(EXTI + 0xC)) // expands to 0x4001040C
// EXTI_PR register: pending register
#define EXTI_PR (*(volatile uint32_t*)(EXTI + 0x14)) // expands to 0x40010414

void enableEXTIIMRRTCInterrupt(void);
void resetEXTIPRRTC(void);
void enableEXTILine0Interrupt(void);
void resetEXTIPR0(void);
void enableEXTILine6Interrupt(void);
void resetEXTIPR6Interrupt(void);

#endif