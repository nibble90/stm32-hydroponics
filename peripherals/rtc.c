#include "rtc.h"
#include "rcc.h"
#include "pwr.h"
#include "exti.h"

/**
* @brief Get the value of RTOFF from RTC_CRL
*
* @return int
*/
int getRTORFF()
{
    return ((RTC_CRL >> 5) & 0b1);
}

/**
* @brief Set the RTC_CRL_CNF bit to high to enter configuration mode
*
* @return void
*/
void setRTCCRLCNFHigh()
{
    RTC_CRL |= RTC_CRL_CNF_MASK(0b1);
}

/**
* @brief Set the RTC_CRL_CNF bit to low to exit configuration mode
*
* @return void
*/
void setRTCCRLCNFLow()
{
    RTC_CRL &= ~RTC_CRL_CNF_MASK(0b1);
}

/**
* @brief Set the RTC_CRH bits to high to enable all interrupts
*
* @details This function sets the 0th, 1st, and 2nd bits of the RTC_CRH register to high
*
* @return void
*/
void setRTCCRHBits()
{
    RTC_CRH |= (0b1 << 0); // ALRIE
    RTC_CRH |= (0b1 << 1); // SECIE
    RTC_CRH |= (0b1 << 2); // CNF
}

/**
* @brief Set the RTC_PRLH bits a value

* @param value: The value to set the RTC_PRLH bits to
*
* @return void
*/
void setRTCPRLL(uint32_t value)
{
    RTC_PRLL = value;
}

/**
* @brief Set the RTC_ALRH bits a value
*
* @param value: The value to set the RTC_ALRH bits to
*
* @return void
*/
void setRTCALRH(uint32_t value)
{
    RTC_ALRH &= value;
}

/**
* @brief Set the RTC_ALRL bits a value
*
* @param value: The value to set the RTC_ALRL bits to
*
* @return void
*/
void setRTCALRL(uint32_t value)
{
    RTC_ALRL &= value;
}

/**
 * @brief Reset the RTC_CNTH register (counter high)
 * 
 * @return void
 */
void resetRTCCNTH(){
    RTC_CNTH = 0x0000;
}

/**
 * @brief Reset the RTC_CNTL register (counter low)
 * 
 * @return void
 */
void resetRTCCNTL(){
    RTC_CNTL = 0x0000;
}

/**
 * @brief Reset the RTC_CRL register
 * 
 * @return void
 */
void resetRTCCRL(){
    RTC_CRL = (uint32_t)0x0020;
}

/**
 * @brief Reset the RTC counter
 * 
 * @details Calls resetRTCCNTH and resetRTCCNTL
 * 
 * @return void
 */
void resetRTCCounter(){
    resetRTCCNTH();
    resetRTCCNTL();
}

/**
 * @brief Reset various registers to de-interrupt the RTC alarm
 * 
 * @return void
 */
void resetRTCAlarm(void){
    resetRTCCRL(); // Reset the RTC_CRL register

    while(getRCCBDCRLSERDY() != 1)
    {
        __asm__ volatile("nop");
    }

    while(getRTORFF() != 1)
    {
        __asm__ volatile("nop");
    }

    setRTCCRLCNFHigh();
    
    resetRTCCounter(); // Reset the RTC counter

    setRTCCRLCNFLow();

    while(getRTORFF() != 1)
    {
        __asm__ volatile("nop");
    }
}

/**
* @brief Setup the RTC alarm interrupt
*
* @return void
*/
void setupRTC()
{
    setupRCCForRTC();
    enableEXTIIMRRTCInterrupt();
    resetRTCCRL();

    while(getRCCBDCRLSERDY() != 1)
    {
        __asm__ volatile("nop");
    }

    while(getRTORFF() != 1)
    {
        __asm__ volatile("nop");
    }

    setRTCCRLCNFHigh();
    
    setRTCPRLL(0x7FFF);
    setRTCALRH(0x0000); // Alarms goes off when counter reaches (high)
    setRTCALRL(0x0010); // Alarms goes off when counter reaches (low)
    resetRTCCounter();
    setRTCCRHBits();

    setRTCCRLCNFLow();

    while(getRTORFF() != 1)
    {
        __asm__ volatile("nop");
    }
}