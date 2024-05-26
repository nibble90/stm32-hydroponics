#include "gpio.h"

/**
 * @brief This function sets the type of a pin to input or output
 * 
 * @param GPIOBlock: The GPIO block to set the pin type for
 * @param pinNumber: The pin number to set the type for
 * @param pinMode: The mode to set the pin to
 */
void setPinType(uint32_t GPIOBlock, int pinNumber, PinMode pinMode){
    if(pinNumber <= 7){
        if(pinMode == output){
            GPIO_CRL_REGISTER(GPIOBlock) &= ~(GPIO_CLR_MODE_MASK(pinNumber));
            GPIO_CRL_REGISTER(GPIOBlock) |= GPIO_CLR_MODE_OUTPUT(pinNumber);
            GPIO_CRL_REGISTER(GPIOBlock) &= ~(GPIO_CLR_CNF_MASK(pinNumber));
            GPIO_CRL_REGISTER(GPIOBlock) |= GPIO_CLR_CNF_OUTPUT(pinNumber);
        }
        else{
            GPIO_CRL_REGISTER(GPIOBlock) &= ~(GPIO_CLR_MODE_MASK(pinNumber));
            GPIO_CRL_REGISTER(GPIOBlock) |= GPIO_CLR_MODE_INPUT(pinNumber);
            GPIO_CRL_REGISTER(GPIOBlock) &= ~(GPIO_CLR_CNF_MASK(pinNumber));
            GPIO_CRL_REGISTER(GPIOBlock) |= GPIO_CLR_CNF_INPUT(pinNumber);
        }
    }
    else if(pinNumber >= 8){
        if(pinMode == output){
            GPIO_CRH_REGISTER(GPIOBlock) &= ~(GPIO_CHR_MODE_MASK(pinNumber));
            GPIO_CRH_REGISTER(GPIOBlock) |= GPIO_CHR_MODE_OUTPUT(pinNumber);
            GPIO_CRH_REGISTER(GPIOBlock) &= ~(GPIO_CHR_CNF_MASK(pinNumber));
            GPIO_CRH_REGISTER(GPIOBlock) |= GPIO_CHR_CNF_OUTPUT(pinNumber);
        }
        else{
            GPIO_CRH_REGISTER(GPIOBlock) &= ~(GPIO_CHR_MODE_MASK(pinNumber));
            GPIO_CRH_REGISTER(GPIOBlock) |= GPIO_CHR_MODE_INPUT(pinNumber);
            GPIO_CRH_REGISTER(GPIOBlock) &= ~(GPIO_CHR_CNF_MASK(pinNumber));
            GPIO_CRH_REGISTER(GPIOBlock) |= GPIO_CHR_CNF_INPUT(pinNumber);
        }
    }

}

/**
 * @brief This function sets the type of several pins to input or output
 * 
 * @param GPIOBlock: The GPIO block to set the pin type for
 * @param pinNumbers: The pin numbers to set the type for
 * @param pinMode: The mode to set the pins to
 */
void setPinTypes(uint32_t GPIOBlock, int pinNumbers[], int sizeOfArray, PinMode pinMode){
    for(int i = 0; i < sizeOfArray; i++){
        setPinType(GPIOBlock, pinNumbers[i], pinMode);
    }

}

/**
 * @brief This function sets the output bit high or low for a given pin.
 * 
 * @param GPIOBlock: The GPIO block to set the pin type for
 * @param pinNumber: The pin number to set the type for
 * @param value: The value to set the pin to (0 for low, 1 for high)
 */
void setPin(uint32_t GPIOBlock, int pinNumber, int value){
    if(pinNumber <= 7){
        if(value == 0){
            GPIO_ODR_REGISTER(GPIOBlock) &= ~(GPIO_ODR_PIN(pinNumber));
        }
        else{
            GPIO_ODR_REGISTER(GPIOBlock) |= GPIO_ODR_PIN(pinNumber);
        }
    }
    else if(pinNumber >= 8){
        if(value == 0){
            GPIO_ODR_REGISTER(GPIOBlock) &= ~(GPIO_ODR_PIN(pinNumber));
        }
        else{
            GPIO_ODR_REGISTER(GPIOBlock) |= GPIO_ODR_PIN(pinNumber);
        }
    }
}

/**
 * @brief This function sets the output bit high or low for several pins.
 * 
 * @param value: The value to set the pin to (0 for low, 1 for high)
 */
void setPins(int value){
    setPin(GPIOB, 11, value);
    setPin(GPIOB, 10, value);
    setPin(GPIOB, 1, value);

    setPin(GPIOB, 9, value);
    setPin(GPIOB, 8, value);
    setPin(GPIOB, 7, value);
    setPin(GPIOB, 6, value);
    setPin(GPIOB, 5, value);
}