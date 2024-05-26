#include "dbg.h"

void allowDebug(void)
{
    DBGMCU_CR |= (uint32_t)(0b1 << 2); // Set the DBG_STANDBY bit to high
    DBGMCU_CR |= (uint32_t)(0b1 << 1); // Set the DBG_STOP bit to high
    //DBGMCU_CR |= (0b1 << 0); // Set the DBG_SLEEP bit to high
}