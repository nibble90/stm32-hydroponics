#ifndef HEADER_FILE_AFIO
#define HEADER_FILE_AFIO

#include "../constants.h"
#include <stdint.h>

#define AFIO_BASE_ADDRESS (PERIPHERAL + 0x10000)

#define AFIO_EXTICR1 (*((volatile uint32_t *)(AFIO_BASE_ADDRESS + 0x08))) // expands to 0x40010008
#define AFIO_EXTICR2 (*((volatile uint32_t *)(AFIO_BASE_ADDRESS + 0x0C))) // expands to 0x4001000C
#define AFIO_EXTICR4 (*((volatile uint32_t *)(AFIO_BASE_ADDRESS + 0x14))) // expands to 0x40010014
#define AFIO_MAPR (*((volatile uint32_t *)(AFIO_BASE_ADDRESS + 0x04))) // expands to 0x40010004

void setB0ToEXTI(void);

#endif