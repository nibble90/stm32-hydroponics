#ifndef HEADER_FILE_GPIO
#define HEADER_FILE_GPIO

#include "../constants.h"
#include <stdint.h>

// GPIO port C registers
#define GPIOC (PERIPHERAL + 0x11000) // expands to 0x40011000
// GPIO port B registers
#define GPIOB (PERIPHERAL + 0x10C00) // expands to 0x40010C00
// GPIO port A registers
#define GPIOA (PERIPHERAL + 0x10800) // expands to 0x40010800

/**
* @brief GPIO port configuration register high registers
*
* @param x: The GPIO registers to access
* 
* @return Pointer for the GPIO port CRH registers for the given GPIO port
*/ 
#define GPIO_CRH_REGISTER(x) (*(volatile uint32_t*)(x + 0x4))

/**
 * @brief GPIO port configuration register low registers
 * 
 * @param x: The GPIO registers to access
 * 
 * @return Pointer for the GPIO port CRL registers for the given GPIO port 
 */
#define GPIO_CRL_REGISTER(x) (*(volatile uint32_t*)(x + 0x0))

/**
* @brief GPIO port configuration register high registers mode mask
*
* @param x: The pin number to generate a 0b11 mask for
*
* @return The mask for the mode bits for the given pin number
*/
#define GPIO_CHR_MODE_MASK(x) (uint32_t)(0b11 << ((x - 8) * 4))

/**
* @brief GPIO port configuration register low registers mode mask
*
* @param x: The pin number to generate a 0b11 mask for
*
* @return The mask for the mode bits for the given pin number
*/
#define GPIO_CLR_MODE_MASK(x) (uint32_t)(0b11 << ((x) * 4))

/**
* @brief GPIO port configuration register high registers mode output
*
* @param x: The pin number to generate 0b01 for
*
* @return The generated value for the mode bits for the given pin number
*/
#define GPIO_CHR_MODE_OUTPUT(x) (uint32_t)(0b01 << ((x - 8) * 4))

/**
* @brief GPIO port configuration register low registers mode output
*
* @param x: The pin number to generate 0b01 for
*
* @return The generated value for the mode bits for the given pin number
*/
#define GPIO_CLR_MODE_OUTPUT(x) (uint32_t)(0b01 << ((x) * 4))

/**
* @brief GPIO port configuration register high registers mode input
*
* @param x: The pin number to generate 0b00 for
*
* @return The generated value for the mode bits for the given pin number
*/
#define GPIO_CHR_MODE_INPUT(x) (uint32_t)(0b00 << ((x - 8) * 4))

/**
* @brief GPIO port configuration register low registers mode input
*
* @param x: The pin number to generate 0b00 for
*
* @return The generated value for the mode bits for the given pin number
*/
#define GPIO_CLR_MODE_INPUT(x) (uint32_t)(0b00 << ((x) * 4))

/**
* @brief GPIO port configuration register high registers configuration mask
*
* @param x: The pin number to generate a 0b11 mask for
*
* @return The mask for the configuration bits for the given pin number
*/
#define GPIO_CHR_CNF_MASK(x) (uint32_t)(0b11 << (((x - 8) * 4) + 2))

/**
* @brief GPIO port configuration register low registers configuration mask
*
* @param x: The pin number to generate a 0b11 mask for
*
* @return The mask for the configuration bits for the given pin number
*/
#define GPIO_CLR_CNF_MASK(x) (uint32_t)(0b11 << (((x) * 4) + 2))

/**
* @brief GPIO port configuration register high registers configuration output
*
* @param x: The pin number to generate 0b00 for
*
* @return The generated value for the configuration bits for the given pin number
*/
#define GPIO_CHR_CNF_OUTPUT(x) (uint32_t)(0b00 << (((x - 8) * 4) + 2))

/**
* @brief GPIO port configuration register low registers configuration output
*
* @param x: The pin number to generate 0b00 for
*
* @return The generated value for the configuration bits for the given pin number
*/
#define GPIO_CLR_CNF_OUTPUT(x) (uint32_t)(0b00 << (((x) * 4) + 2))

/**
* @brief GPIO port configuration register high registers configuration input
*
* @param x: The pin number to generate 0b01 for
*
* @return The generated value for the configuration bits for the given pin number
*/
#define GPIO_CHR_CNF_INPUT(x) (uint32_t)(0b10 << (((x - 8) * 4) + 2))

/**
* @brief GPIO port configuration register low registers configuration input
*
* @param x: The pin number to generate 0b01 for
*
* @return The generated value for the configuration bits for the given pin number
*/
#define GPIO_CLR_CNF_INPUT(x) (uint32_t)(0b10 << (((x) * 4) + 2))

/**
* @brief GPIO port output data register
*
* @param x: The GPIO registers to access
*
* @return Pointer for the GPIO port ODR registers for the given GPIO port
*/
#define GPIO_ODR_REGISTER(x) (*(volatile uint32_t *)(x + 0xC))

/**
* @brief GPIO port output data register pin
*
* @param x: The pin number to generate a 1 for
*
* @return The generated value for the pin number
*/
#define GPIO_ODR_PIN(x) (uint32_t)(1 << x)

#define GPIO_IDR_REGISTER(x) (*(volatile uint32_t *)(x + 0x8))

/**
 * @brief Pin mode
 * 
 * @details This enum is used to set the mode of a pin to input or output
 * 
 * @param input: The pin is set to input
 * @param output: The pin is set to output
 */
typedef enum{
    input = 0,
    output = 1
} PinMode;

void setPinType(uint32_t GPIOBlock, int pinNumber, PinMode pinMode);
void setPinTypes(uint32_t GPIOBlock, int pinNumbers[], int sizeOfArray, PinMode pinMode);
void setPin(uint32_t GPIOBlock, int pinNumber, int value);
void setPins(int value);
int getPin(uint32_t GPIOBlock, int pinNumber);

#endif