#include "dbg.h"

void allowDebug(void)
{
    //DBGMCU_CR |= (uint32_t)(0b1 << 2); // Set the DBG_STANDBY bit to high
    //DBGMCU_CR |= (uint32_t)(0b1 << 1); // Set the DBG_STOP bit to high
    DBGMCU_CR |= (0b1 << 0); // Set the DBG_SLEEP bit to high
}

void disableTimerCounterInDebug(TIMER timer){
    switch(timer){
        case TIM2:
            DBGMCU_CR |= (0b1 << 11);
            break;
        case TIM3:
            DBGMCU_CR |= (0b1 << 12);
            break;
    }
}