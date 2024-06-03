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


/**
 * @brief Enables the EXTI Line 3 interrupt.
 * 
 * @return void
 */
void enableEXTILine3Interrupt()
{
    EXTI_IMR |= (0b1 << 3);
    EXTI_EMR |= (0b1 << 3);
    EXTI_RTSR |= (0b1 << 3);
}

/**
 * @brief Enables the EXTI Line 4 interrupt.
 * 
 * @return void
 */
void enableEXTILine4Interrupt()
{
    EXTI_IMR |= (0b1 << 4);
    EXTI_EMR |= (0b1 << 4);
    EXTI_RTSR |= (0b1 << 4);
}

/**
 * @brief Enables the EXTI Line 6 interrupt.
 * 
 * @return void
 */
void enableEXTILine6Interrupt()
{
    EXTI_IMR |= (0b1 << 6);
    EXTI_EMR |= (0b1 << 6);
    EXTI_RTSR |= (0b1 << 6);
}

void enableEXTILine15Interrupt()
{
    EXTI_IMR |= (0b1 << 15);
    EXTI_EMR |= (0b1 << 15);
    EXTI_RTSR |= (0b1 << 15);
}

/**
 * @brief Resets the EXTI Line 3 interrupt pending flag.
 * 
 * @return void
 */
void resetEXTILine3Interrupt()
{
    EXTI_PR &= (uint32_t)(0b1 << 3);
}

/**
 * @brief Resets the EXTI Line 4 interrupt pending flag.
 * 
 * @return void
 */
void resetEXTILine4Interrupt()
{
    EXTI_PR &= (uint32_t)(0b1 << 4);
}

/**
 * @brief Resets the EXTI Line 6 interrupt pending flag.
 * 
 * @return void
 */
void resetEXTILine6Interrupt()
{
    EXTI_PR &= (uint32_t)(0b1 << 6);
}

void resetEXTILine15Interrupt()
{
    EXTI_PR &= (uint32_t)(0b1 << 15);
}