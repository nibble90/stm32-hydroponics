#include "rcc.h"
#include "pwr.h"

/**
 * @brief This function opens the clock gate for port C.
 *
 * @details It enables the clock register for port C by setting the 4th bit high of the RCC_APB2ENR register.
 *
 * @return void
 */
void openPortCClockGate()
{
    RCC_APB2ENR |= (0b1 << 4);
}

/**
 * @brief This function opens the clock gate for port B.
 *
 * @details It enables the clock register for port B by setting the 3rd bit high of the RCC_APB2ENR register.
 *
 * @return void
 */
void openPortBClockGate()
{
    RCC_APB2ENR |= (0b1 << 3);
    RCC_APB2ENR |= (0b1 << 0);
}

/**
* @brief Enable the RCC_APB1ENR registers for the RTC
*
* @details This function sets the provided bit of the RCC_APB1ENR register to high
*
* @param bit: The bit to set high
*
* @return void
*/
void enableRCCAPB1ENRRegisters(int bit){
    RCC_APB1ENR |= (0b1 << bit);
}

/**
* @brief Enable the RCC_BDCR register for the RTC clock
*
* @details This function sets the 15th bit (RTCEN) of the RCC_BDCR register to high to enable the RTC clock
*
* @return void
*/
void enableRCCBDCRRTCClock()
{
    RCC_BDCR |= (0b1 << 15);
}

/**
* @brief Set the RCC_BDCR register to make RTC use the LSE clock
*
* @details This function sets the 9th and 8th bits (RTCSEL) of the RCC_BDCR register to 01 to use the LSE clock
*
* @return void
*/
void setRCCClockSourceToLSE()
{
    RCC_BDCR |= (0b01 << 8);
}

/**
* @brief Set the RCC_BDCR register to turn on the LSE clock
*
* @details This function sets the 0th bit of the RCC_BDCR register to high
*
* @return void
*/
void setRCCBDCRLSEON()
{
    RCC_BDCR |= (0b1 << 0);
}

/**
* @brief Get the RCC_BDCR register LSE ready bit
*
* @return int
*/
int getRCCBDCRLSERDY()
{
    return ((RCC_BDCR >> 1) & 0b1);
}

void setAPB1Prescaler(uint32_t prescaler){
    RCC_CFGR |= (prescaler << 8);
}

void setAHBPrescaler(uint32_t prescaler){
    RCC_CFGR |= (prescaler << 4);
}
/**
* @brief Set various RCC registers required for the RTC
*
* @return void
*/
void setupRCCForRTC(){
    enableRCCAPB1ENRRegisters(27);
    enableRCCAPB1ENRRegisters(28);

    enablePWRCRDBP();
    
    setRCCClockSourceToLSE();
    setRCCBDCRLSEON();

    enableRCCBDCRRTCClock();
}

void enableTimerClock(TIMER timer){
    switch(timer){
        case TIM3:
            RCC_APB1ENR |= (0b1 << 1);
            break;
        case TIM4:
            RCC_APB1ENR |= (0b1 << 2);
            break;
        case TIM5:
            RCC_APB1ENR |= (0b1 << 3);
            break;
    }
}