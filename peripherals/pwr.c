#include "pwr.h"

/**
* @brief Enable the DBP bit in the PWR_CR register
*
* @details This function sets the 8th bit of the PWR_CR register to high
*
* @return void
*/
void enablePWRCRDBP()
{
    PWR_CR |= (0b1 << 8);
}

/**
 * @brief Set the PDDS bit in the PWR_CR register
 * 
 * @details This function sets the 1st bit of the PWR_CR register to 
 * high to enable standby mode or low to enable stop mode
 * 
 * @param mode: 1 to enable standby mode, 0 to enable stop mode
 * 
 * @return void 
 */
void setPDDS(int mode)
{
    if (mode == 1)
    {
        PWR_CR |= (uint32_t)(0b1 << 1);
    }
    else
    {
        PWR_CR &= ~(uint32_t)(0b1 << 1);
    }
}

/**
 * @brief Set the CWUF bit in the PWR_CR register to high
 * 
 * @details This function sets the 2nd bit of the PWR_CR register to high to clear the wakeup flag
 * 
 * @return void 
 */
void setCWUFBit()
{
    PWR_CR |= (0b1 << 2);
}

/**
 * @brief Set the LPSDSR bit in the PWR_CR register
 * 
 * @details This function sets the 0th bit of the PWR_CR register to high to enable low-power deep sleep mode
 * 
 * @param mode: 1 to enable low-power deep sleep mode, 0 to disable low-power deep sleep mode
 * 
 * @return void 
 */
void setLPPS(int mode)
{
    if (mode == 1)
    {
        PWR_CR |= (uint32_t)(0b1 << 0);
    }
    else
    {
        PWR_CR &= ~(uint32_t)(0b1 << 0);
    }
}