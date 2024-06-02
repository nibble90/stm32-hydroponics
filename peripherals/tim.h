#ifndef HEADER_FILE_TIM
#define HEADER_FILE_TIM

#include <stdint.h>
#include "../constants.h"
#include "rcc.h"

#define TIM3_BASE_ADDRESS (PERIPHERAL + 0x0400)
#define TIM4_BASE_ADDRESS (PERIPHERAL + 0x0800)
#define TIM5_BASE_ADDRESS (PERIPHERAL + 0x0C00)

#define TIMx_CR1(x) (*((volatile uint32_t *)(x + 0x00)))
#define TIMx_CR2(x) (*((volatile uint32_t *)(x + 0x04)))
#define TIMx_DIER(x) (*((volatile uint32_t *)(x + 0x0C)))
#define TIMx_SR(x) (*((volatile uint32_t *)(x + 0x10)))
#define TIMx_EGR(x) (*((volatile uint32_t *)(x + 0x14)))
#define TIMx_CNT(x) (*((volatile uint32_t *)(x + 0x24)))
#define TIMx_PSC(x) (*((volatile uint32_t *)(x + 0x28)))
#define TIMx_ARR(x) (*((volatile uint32_t *)(x + 0x2C)))

void enableTimerInterrupt(TIMER timer);
void enableTimerCounter(TIMER timer);
void generateTimerRegisterUpdate(TIMER timer);
void passTimerReloadValueIntoRegister(TIMER timer, uint32_t autoReloadValue);
void setTimerEventSourceToOverflow(TIMER timer);
void setTimerPrescaler(TIMER timer, uint32_t prescaler);
void resetTimerInterrupt(TIMER timer);
void setupTimer(TIMER timer);
void startTimer(TIMER timer, uint32_t autoReloadValue);

#endif