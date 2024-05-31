#ifndef HEADER_FILE_FILLTANK
#define HEADER_FILE_FILLTANK

#include <stdint.h>
#include "../constants.h"
#include "../peripherals/gpio.h"

void fillTank();
void turnPumpsOn();
void turnPumpsOff();

#endif