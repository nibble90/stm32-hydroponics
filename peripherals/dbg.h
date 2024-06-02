#ifndef HEADER_FILE_DGB
#define HEADER_FILE_DGB

#include <stdint.h>
#include "../constants.h"

// DBG addresses start here
#define DBG 0xE0042000

// DBGMCU_CR
#define DBGMCU_CR (*(volatile uint32_t *)(DBG + 0x04)) // expands to 0xE0042004

void allowDebug(void);
void disableTimerCounterInDebug(TIMER timer);

#endif