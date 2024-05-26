#include "afio.h"

/**
 * @brief This function sets the B0 pin to the EXTI interrupt line
 * 
 * @return void  
 */
void setB0ToEXTI(void){
    AFIO_EXTICR1 |= (uint32_t)0b1;
}