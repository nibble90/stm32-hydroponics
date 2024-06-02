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


/**
 * Enables the interrupt for the specified timer.
 *
 * @param timer The timer to enable the interrupt for.
 */
void enableTimerInterrupt(TIMER timer){
    switch(timer){
        case TIM3:
            NVIC_ISER0 |= NVIC_ISERx_MASK(29);
            break;
        case TIM4:
            NVIC_ISER0 |= NVIC_ISERx_MASK(30);
            break;
        case TIM5:
            NVIC_ISER1 |= NVIC_ISERx_MASK(12);
            break;
    }
}

/**
 * @brief Clears the interrupt for the specified timer.
 * 
 * @param timer The timer for which to clear the interrupt.
 */
void clearTimerInterrupt(TIMER timer){
    switch(timer){
        case TIM3:
            NVIC_ICPR0 |= NVIC_ISERx_MASK(29);
            break;
        case TIM4:
            NVIC_ICPR0 |= NVIC_ISERx_MASK(30);
            break;
        case TIM5:
            NVIC_ICPR1 |= NVIC_ISERx_MASK(12);
            break;
    }
}