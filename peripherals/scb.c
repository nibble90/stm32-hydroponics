#include "scb.h"

/**
 * @brief Set the SLEEPDEEP bit in the SCB_SCR register
 * 
 * @details This function sets the 2nd bit of the SCB_SCR register to
 * high to enable deep sleep mode or low to enable sleep mode
 * 
 * @param mode: 1 to enable deep sleep mode, 0 to enable sleep mode
 * 
 * @return void
 */
void setDeepSleep(int mode)
{
    if (mode == 1)
    {
        SCB_SCR |= (uint32_t)(0b1 << 2);
    }
    else
    {
        SCB_SCR &= ~(uint32_t)(0b1 << 2);
    }
}