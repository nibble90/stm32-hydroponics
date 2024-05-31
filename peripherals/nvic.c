#include "nvic.h"

/**
 * @brief Enable the NVIC RTC Alarm interrupt
 * 
 * @details This function sets the 9th bit (RTC Alarm) of the NVIC_ISER1 register to high
 * 
 * @return void  
 */
void enableRTCAlarmInterrupt(void)
{
    NVIC_ISER1 |= NVIC_ISERx_MASK(9);
}

/**
 * @brief Clear the NVIC RTC Alarm interrupt
 * 
 * @details This function sets the 9th bit (RTC Alarm) of the NVIC_ICPR1 register to high
 * 
 * @return void
 */
void clearRTCAlarmInterrupt(void)
{
    NVIC_ICPR1 |= NVIC_ISERx_MASK(9);
}

/**
 * @brief Enable the NVIC Line 0 interrupt
 * 
 * @details This function sets the 0th bit of the NVIC_ISER0 register to high
 * 
 * @return void
 */
void enableLine0Interrupt(void)
{
    NVIC_ISER0 |= NVIC_ISERx_MASK(6);
}

/**
 * @brief Clear the NVIC Line 0 interrupt
 * 
 * @details This function sets the 0th bit of the NVIC_ICPR0 register to high
 * 
 * @return void
 */
void clearLine0Interrupt(void)
{
    NVIC_ICPR0 |= NVIC_ISERx_MASK(6);
}

void enableTimer3Interrupt(void){
    NVIC_ISER0 |= NVIC_ISERx_MASK(29);
}

void clearTimer3Interrupt(void){
    NVIC_ICPR0 |= NVIC_ISERx_MASK(29);
}