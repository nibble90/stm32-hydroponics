#include "fill-tank.h"

void fillTank(){
    setPins(1);
}

void stopFillingTank(){
    setPins(0);
}

void maintainTank(){
    setPin(GPIOB, PUMP1_PIN, 1);
}

void stopMaintainingTank(){
    setPin(GPIOB, PUMP1_PIN, 0);
}