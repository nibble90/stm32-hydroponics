#include "fill-tank.h"

void fillTank(){
    setPin(GPIOC, PUMP1_PIN, 1);
    setPin(GPIOC, PUMP2_PIN, 1);
    setPin(GPIOC, PUMP3_PIN, 1);
}

void stopFillingTank(){
    setPin(GPIOC, PUMP1_PIN, 0);
    setPin(GPIOC, PUMP2_PIN, 0);
    setPin(GPIOC, PUMP3_PIN, 0);
}

void maintainTank(){
    setPin(GPIOC, PUMP1_PIN, 1);
}

void stopMaintainingTank(){
    setPin(GPIOC, PUMP1_PIN, 0);
}