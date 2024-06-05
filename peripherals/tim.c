#include "tim.h"


/**
 * @brief Enables the interrupt for the specified timer.
 *
 * @param timer The timer to enable the interrupt for.
 * 
 * @return void
 */
void enableTimerInterrupt(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_DIER(TIM2_BASE_ADDRESS) |= 0x01;
            break;
        case TIM3:
            TIMx_DIER(TIM3_BASE_ADDRESS) |= 0x01;
            break;
    }
}

/**
 * @brief Enables the counter for the specified timer.
 *
 * @param timer The timer to enable the counter for.
 * 
 * @return void
 */
void enableTimerCounter(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_CR1(TIM2_BASE_ADDRESS) |= 0x01;
            break;
        case TIM3:
            TIMx_CR1(TIM3_BASE_ADDRESS) |= 0x01;
            break;
    }
}

/**
 * @brief Generates an update of the registers for the specified timer.
 *
 * @param timer The timer to enable the update generation for.
 * 
 * @return void
 */
void generateTimerRegisterUpdate(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_EGR(TIM2_BASE_ADDRESS) |= 0x01;
            break;
        case TIM3:
            TIMx_EGR(TIM3_BASE_ADDRESS) |= 0x01;
            break;
    }
}

/**
 * @brief Passes the auto reload value into the register for the specified timer.
 *
 * @param timer The timer to pass the auto reload value into.
 * @param autoReloadValue The value to pass into the register.
 * 
 * @return void
 */
void passTimerReloadValueIntoRegister(TIMER timer, uint32_t autoReloadValue){
    switch(timer){
        case TIM2:
            TIMx_ARR(TIM2_BASE_ADDRESS) = autoReloadValue;
            break;
        case TIM3:
            TIMx_ARR(TIM3_BASE_ADDRESS) = autoReloadValue;
            break;
    }
}

/**
 * @brief Sets the event source to overflow for the specified timer.
 *
 * @param timer The timer to set the event source to overflow for.
 * 
 * @return void
 */
void setTimerEventSourceToOverflow(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_CR1(TIM2_BASE_ADDRESS) |= (0x01 << 2);
            break;
        case TIM3:
            TIMx_CR1(TIM3_BASE_ADDRESS) |= (0x01 << 2);
            break;
    }
}

/**
 * @brief Sets the timer prescaler for the specified timer.
 *
 * @param timer The timer to set the prescaler for.
 * @param prescaler The value to set the prescaler to.
 * 
 * @return void
 */
void setTimerPrescaler(TIMER timer, uint32_t prescaler){
    switch(timer){
        case TIM2:
            TIMx_PSC(TIM2_BASE_ADDRESS) = prescaler;
            break;
        case TIM3:
            TIMx_PSC(TIM3_BASE_ADDRESS) = prescaler;
            break;
    }
}

/**
 * @brief Resets the interrupt for the specified timer.
 *
 * @param timer The timer to reset the interrupt for.
 * 
 * @return void
 */
void resetTimerInterrupt(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_SR(TIM2_BASE_ADDRESS) &= ~(uint32_t)(0b01);
            break;
        case TIM3:
            TIMx_SR(TIM3_BASE_ADDRESS) &= ~(uint32_t)(0b01);
            break;
    }
}

/**
 * @brief Disables the timer counter for the specified timer.
 *
 * @param timer The timer to disable.
 * 
 * @return void
 */
void disableTimerCounter(TIMER timer){
    switch(timer){
        case TIM2:
            TIMx_CR1(TIM2_BASE_ADDRESS) &= ~(uint32_t)(0x01);
            break;
        case TIM3:
            TIMx_CR1(TIM3_BASE_ADDRESS) &= ~(uint32_t)(0x01);
            break;
    }
}

void setupTimer(TIMER timer){
    enableTimerClock(timer);
    setTimerEventSourceToOverflow(timer);
    setTimerPrescaler(timer, 62500);
    enableTimerInterrupt(timer);
    generateTimerRegisterUpdate(timer);
}

void startTimer(TIMER timer, uint32_t autoReloadValue){
    passTimerReloadValueIntoRegister(timer, autoReloadValue*4);
    generateTimerRegisterUpdate(timer);
    enableTimerCounter(timer);
}