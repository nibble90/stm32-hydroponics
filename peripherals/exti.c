#include "exti.h"

/**
 * @brief Enable the EXTI RTC interrupt
 * 
 * @details This function sets the 17th bit (RTC Alarm) of
 * EXTI_IMR and EXTI_RTSR registers to high
 * 
 * @return void
 */
void enableEXTIIMRRTCInterrupt()
{
    EXTI_IMR |= (0b1 << 17);
    EXTI_RTSR |= (0b1 << 17);
}

/**
 * @brief Enable the EXTI Line 0 interrupt
 * 
 * @details This function sets the 0th bit of EXTI_IMR and EXTI_RTSR to high
 * 
 * @return void
 */
void enableEXTILine0Interrupt()
{
    EXTI_IMR |= (0b1 << 0);
    EXTI_FTSR |= (0b1 << 0);
}

/**
 * @brief Reset the EXTI RTC Alarm pending interrupt bit
 * 
 * @details This function sets the 17th bit (RTC ALARM) of the EXTI_PR register to high
 * 
 * @return void
 */
void resetEXTIPRRTC(){
    EXTI_PR &= (uint32_t)(0b1 << 17);
}

/**
 * @brief Reset the EXTI Line 0 pending interrupt bit
 * 
 * @details This function sets the 0th bit of the EXTI_PR register to high
 * 
 * @return void
 */
void resetEXTIPR0(){
    EXTI_PR &= (uint32_t)(0b1 << 0);
}

void enableEXTILine6Interrupt(){
    EXTI_IMR |= (0b1 << 6);
    EXTI_EMR |= (0b1 << 6);
    EXTI_RTSR |= (0b1 << 6);
}

void resetEXTIPR6(){
    EXTI_PR &= (uint32_t)(0b1 << 6);
}