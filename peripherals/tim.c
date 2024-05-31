#include "tim.h"

void enableTimerInterrupt(TIMER timer){
    switch(timer){
        case TIM3:
            TIMx_DIER(TIM3_BASE_ADDRESS) |= 0x01;
            //TIMx_DIER(TIM3_BASE_ADDRESS) |= (0x01 << 6);
            break;
        case TIM4:
            TIMx_DIER(TIM4_BASE_ADDRESS) |= 0x01;
            TIMx_DIER(TIM4_BASE_ADDRESS) |= (0x01 << 6);
            break;
        case TIM5:
            TIMx_DIER(TIM5_BASE_ADDRESS) |= 0x01;
            TIMx_DIER(TIM5_BASE_ADDRESS) |= (0x01 << 6);
            break;
    }
}

void enableTimerCounter(TIMER timer){
    switch(timer){
        case TIM3:
            TIMx_CR1(TIM3_BASE_ADDRESS) |= 0x01;
            break;
        case TIM4:
            TIMx_CR1(TIM4_BASE_ADDRESS) |= 0x01;
            break;
        case TIM5:
            TIMx_CR1(TIM5_BASE_ADDRESS) |= 0x01;
            break;
    }
}

void enableTimerUpdateGeneration(TIMER timer){
    switch(timer){
        case TIM3:
            TIMx_EGR(TIM3_BASE_ADDRESS) |= 0x01;
            break;
        case TIM4:
            TIMx_EGR(TIM4_BASE_ADDRESS) |= 0x01;
            break;
        case TIM5:
            TIMx_EGR(TIM5_BASE_ADDRESS) |= 0x01;
            break;
    }
}

void passTimerReloadValueIntoRegister(TIMER timer, uint32_t autoReloadValue){
    switch(timer){
        case TIM3:
            TIMx_ARR(TIM3_BASE_ADDRESS) = autoReloadValue;
            break;
        case TIM4:
            TIMx_ARR(TIM4_BASE_ADDRESS) = autoReloadValue;
            break;
        case TIM5:
            TIMx_ARR(TIM5_BASE_ADDRESS) = autoReloadValue;
            break;
    }
}

void setTimerEventSourceToOverflow(TIMER timer){
    switch(timer){
        case TIM3:
            TIMx_CR1(TIM3_BASE_ADDRESS) |= (0x01 << 2);
            break;
        case TIM4:
            TIMx_CR1(TIM4_BASE_ADDRESS) |= (0x01 << 2);
            break;
        case TIM5:
            TIMx_CR1(TIM5_BASE_ADDRESS) |= (0x01 << 2);
            break;
    }
}