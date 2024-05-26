#ifndef HEADER_FILE_SCB
#define HEADER_FILE_SCB

#include <stdint.h>

// SCB addresses start here
#define SCB 0xE000ED00

// SCB_SCR register
#define SCB_SCR (*(volatile uint32_t *)(SCB + 0x10)) // expands to 0xE000ED10

void setDeepSleep(int mode);

#endif