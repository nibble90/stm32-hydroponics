#ifndef HEADER_FILE_PWR
#define HEADER_FILE_PWR

#include "../constants.h"
#include <stdint.h>

// PWR addresses start here
#define PWR (PERIPHERAL + 0x7000) // expands to 0x40007000
// PWR_CR register
#define PWR_CR (*(volatile uint32_t*)(PWR))
// PWR_CSR register
#define PWR_CSR (*(volatile uint32_t*)(PWR + 0x04)) // expands to 0x40007004


void enablePWRCRDBP(void);
void setPDDS(int mode);
void setCWUFBit(void);
void setLPPS(int mode);

#endif