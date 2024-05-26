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
    //allowDebug(); // Allow debug in stop mode

    openPortCClockGate();
    openPortBClockGate();

    setB0ToEXTI();

    setPinType(GPIOC, 13, output); // onboard LED
    setPinType(GPIOB, 0, input); // B0 to input

    setPinTypes(GPIOB, (int[]){11, 10, 1, 9, 8, 7, 6, 5}, 8, output);
    
    // setupRTC();
    
    // enableRTCAlarmInterrupt();
    enableEXTILine0Interrupt();
    enableLine0Interrupt();

    setPin(GPIOC, 13, 0); // 0 == LED on
    //setPins(1);
    doNothing(100000);
    setPin(GPIOC, 13, 1);
    //setPins(0);

    setDeepSleep(1); // Set the deep sleep bit high
    setPDDS(0); // Use stop mode in deep sleep
    setLPPS(1); // Enable low-power deep sleep mode

    for (;;){
        // Set the output bit low (LED on)
        doNothing(600000);
        setPin(GPIOC, 13, 0);
        doNothing(600000);
        // Set the output bit high (LED off)
        setPin(GPIOC, 13, 1);

        __asm__ volatile("DSB"); // Data synchronization barrier to ensure all memory accesses are complete
        __asm__ volatile("WFI"); // Wait for event
        __asm__ volatile("ISB"); // Instruction synchronization barrier to flush the pipeline
    }

    return 0;
}

/**
 * @brief RTC Alarm interrupt handler
 * 
 * @return void
 */
extern void RTC_Alarm_IRQHandler(void){
    resetRTCAlarm();
    resetEXTIPRRTC();
    clearRTCAlarmInterrupt();
    for (int i = 0; i < 2; i++)
    {
        setPin(GPIOC, 13, 0);
        doNothing(100000);
        setPin(GPIOC, 13, 1);
        doNothing(100000);
    }
}

extern void EXTI0_IRQHandler(void){
    resetEXTIPR0();
    clearLine0Interrupt();
    for (int i = 0; i < 30; i++)
    {
        setPins(1);
        doNothing(300000);
        setPins(0);

        doNothing(350000);

        setPins(1);
        doNothing(300000);
        setPins(0);

        doNothing(600000);
    }
}