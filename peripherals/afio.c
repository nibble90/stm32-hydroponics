#include "afio.h"

/**
 * @brief This function sets the B0 pin to the EXTI interrupt line
 * 
 * @return void  
 */
void setB0ToEXTI(void){
    AFIO_EXTICR1 |= (uint32_t)0b1;
}

/**
 * @brief Remaps TIM2 Channel 1 to PA15.
 * 
 * @return void
 */
void remapTIM2CH1ToPA15(void){
    AFIO_MAPR |= (uint32_t)(0b01 << 8);
}