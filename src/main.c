#include "../peripherals/gpio.h"
#include "../peripherals/afio.h"
#include "../peripherals/nvic.h"
#include "../peripherals/rcc.h"
#include "../peripherals/rtc.h"
#include "../peripherals/pwr.h"
#include "../peripherals/exti.h"
#include "../peripherals/scb.h"
#include "../peripherals/dbg.h"
#include "../peripherals/afio.h"
#include "../peripherals/tim.h"
#include "fill-tank.h"


int currentlyFilling  = 0;
int currentlyMaintaining = 0;
int currentlyWaiting = 0;

/**
 * @brief This function does nothing for a given number of iterations.
 * 
 * @details It uses the nop assembly instruction to do nothing for a given number of iterations.
 * 
 * @param iterations The number of iterations to do nothing for.
 * 
 * @return void
 */
void doNothing(int iterations){
    for(uint32_t i = 0; i < iterations; ++i){
        __asm__ volatile("nop");
    }
}

/**
 * @brief Main function
 * 
 * @return 0 
 */
int main()
{
    //enableMultipleTimers();
    allowDebug(); // Allow debug in sleep mode
    disableTimerCounterInDebug(TIM3);
    disableTimerCounterInDebug(TIM2);

    openPortCClockGate();
    openPortBClockGate();
    //enableAFIOClock();

    //enableAllClocks();


    // setB0ToEXTI();

    setPinType(GPIOC, 13, output); // onboard LED
    setPinType(GPIOB, 0, input); // B0 to input
    setPinTypes(GPIOB, (int[]){PUMP1_PIN, PUMP2_PIN, PUMP3_PIN}, 3, output);
    
    // setupRTC();
    
    // enableRTCAlarmInterrupt();
    // enableLine0Interrupt();
    // enableEXTILine0Interrupt();
    //enableEXTILine3Interrupt();
    //enableEXTILine15Interrupt();
    enableTimerNVICInterrupt(TIM2);
    enableTimerNVICInterrupt(TIM3);

    setPin(GPIOC, 13, 0); // 0 == LED on
    //setPins(1);
    doNothing(12000000); // provide an opportunity to stop the program
    setPin(GPIOC, 13, 1);
    setPins(0);

    //setAHBPrescaler(0b1011);
    setAPB1Prescaler(0b111);

    setupTimer(TIM2);
    setupTimer(TIM3);

    setDeepSleep(0); // Set the deep sleep bit high
    //setPDDS(0); // Use stop mode in deep sleep
    //setLPPS(1); // Enable low-power deep sleep mode

    if(ENABLE_LIGHT_STAGE_SWITCH){
        for (;;){
            if(!currentlyWaiting){
                if(!currentlyFilling && !currentlyMaintaining){
                    currentlyFilling = 1;
                    currentlyWaiting = 1;
                    startTimer(TIM2, STAGE1_FILL_TIME);
                    fillTank();
                }else if(currentlyFilling && !currentlyMaintaining){
                    currentlyFilling = 0;
                    currentlyMaintaining = 1;
                    currentlyWaiting = 1;
                    startTimer(TIM3, STAGE2_TIME);
                    stopFillingTank();
                    maintainTank();
                }else{
                    currentlyFilling = 0;
                    currentlyMaintaining = 0;
                    currentlyWaiting = 1;
                    startTimer(TIM2, getPin(GPIOB, LDR_PIN) ? STAGE1_WAIT_TIME_LIGHT : STAGE1_WAIT_TIME_DARK);
                    stopMaintainingTank();
                }
            }
            __asm__ volatile("WFI");
        }
    }
    else{
        for (;;){
            if(!currentlyWaiting){
                if(!currentlyFilling && !currentlyMaintaining){
                    currentlyFilling = 1;
                    currentlyWaiting = 1;
                    startTimer(TIM2, STAGE1_FILL_TIME);
                    // fill tank
                }else if(currentlyFilling && !currentlyMaintaining){
                    currentlyFilling = 0;
                    currentlyMaintaining = 1;
                    currentlyWaiting = 1;
                    startTimer(TIM3, STAGE2_TIME);
                    // stop filling tank
                    // start maintaining tank
                }else{
                    currentlyFilling = 0;
                    currentlyMaintaining = 0;
                    currentlyWaiting = 1;
                    startTimer(TIM2, STAGE1_WAIT_TIME_LIGHT);
                    // stop maintaining tank
                }
            }
            __asm__ volatile("WFI");
        }
    }

    return 0;
}

/**
 * @brief RTC Alarm interrupt handler
 * 
 * @return void
 */
// extern void RTC_Alarm_IRQHandler(void){
//     resetRTCAlarm();
//     resetEXTIPRRTC();
//     clearRTCAlarmInterrupt();
//     for (int i = 0; i < 2; i++)
//     {
//         setPin(GPIOC, 13, 0);
//         doNothing(100000);
//         setPin(GPIOC, 13, 1);
//         doNothing(100000);
//     }
// }

// extern void EXTI0_IRQHandler(void){
//     resetEXTIPR0();
//     clearLine0Interrupt();
//     for (int i = 0; i < 30; i++)
//     {
//         setPins(1);
//         doNothing(300000);
//         setPins(0);

//         doNothing(350000);

//         setPins(1);
//         doNothing(300000);
//         setPins(0);

//         doNothing(600000);
//     }
// }

extern void TIM2_IRQHandler(void){
    resetTimerInterrupt(TIM2);
    //resetEXTILine15Interrupt();
    clearTimerNVICInterrupt(TIM2);
    disableTimerCounter(TIM2);

    currentlyWaiting = !currentlyWaiting;
}

extern void TIM3_IRQHandler(void){
    resetTimerInterrupt(TIM3);
    //resetEXTILine4Interrupt
    clearTimerNVICInterrupt(TIM3);
    disableTimerCounter(TIM3);

    currentlyWaiting = !currentlyWaiting;
}