#ifndef HEADER_FILE_AFIO
#define HEADER_FILE_AFIO

#include "../constants.h"
#include <stdint.h>

#define AFIO_BASE_ADDRESS (PERIPHERAL + 0x10000)

#define AFIO_EXTICR1 (*((volatile uint32_t *)(AFIO_BASE_ADDRESS + 0x08))) // expands to 0x40010008

void setB0ToEXTI(void);

#endif