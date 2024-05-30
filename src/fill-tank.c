#include "fill-tank.h"

void fillTank(){
    // Turn all pumps on
    turnPumpsOn();
    // Wait for the tank to fill
    doNothing(PUMP1_FILL_TIME);
    // Turn all pumps off
    turnPumpsOff();
}

void turnPumpsOn(){
    setPin(GPIOC, PUMP1_PIN, 0);
    setPin(GPIOC, PUMP2_PIN, 0);
    setPin(GPIOC, PUMP3_PIN, 0);
}

void turnPumpsOff(){
    setPin(GPIOC, PUMP1_PIN, 1);
    setPin(GPIOC, PUMP2_PIN, 1);
    setPin(GPIOC, PUMP3_PIN, 1);
}