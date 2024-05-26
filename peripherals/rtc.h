#ifndef HEADER_FILE_RTC
#define HEADER_FILE_RTC

#include "../constants.h"
#include <stdint.h>

// RTC addresses start here
#define RTC (PERIPHERAL + 0x2800) // expands to 0x40002800
// RTC Control Register High
#define RTC_CRH (*(volatile uint32_t*)(RTC))
// RTC Control Register Low
#define RTC_CRL (*(volatile uint32_t*)(RTC + 0x4)) // expands to 0x40002804
// RTC Prescaler Load Register Low
#define RTC_PRLL (*(volatile uint32_t*)(RTC + 0xC)) // expands to 0x4000280C
// RTC Alarm Register High
#define RTC_ALRH (*(volatile uint32_t*)(RTC + 0x20)) // expands to 0x40002820
// RTC Alarm Register Low
#define RTC_ALRL (*(volatile uint32_t*)(RTC + 0x24)) // expands to 0x40002824
// RTC Counter Register High
#define RTC_CNTH (*(volatile uint32_t*)(RTC + 0x18)) // expands to 0x40002818
// RTC Counter Register Low
#define RTC_CNTL (*(volatile uint32_t*)(RTC + 0x1c)) // expands to 0x4000281C

/*
* @brief Get a mask for the configuration bit in RTC_CRL
*
* @details This function does a left shift of four bits on the input value
*
* @param x: bit to be shifted
*
* @return uint32_t of the shifted bit
*/
#define RTC_CRL_CNF_MASK(x) (uint32_t)(x << 4)

void setupRTC(void);

void resetRTCAlarm(void);

#endif