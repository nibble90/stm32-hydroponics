#ifndef HEADER_FILE_CONSTANTS
#define HEADER_FILE_CONSTANTS

#include <stdint.h>
#include "typedefs.h"

#define minutesToSeconds(x) (x * 60)
#define hoursToSeconds(x) (x * 3600)

// Peripheral addresses start here
#define PERIPHERAL 0x40000000

// Config Settings
#define PUMP1_PIN 7
#define PUMP2_PIN 9
#define PUMP3_PIN 8 // pump 3 currently dead
#define LDR_PIN 0

//  Maximum values:
//      Seconds: 16383
//      Minutes: 273
//      Hours: 4.55

// Stage 1 must be less time than stage 2

#define STAGE1_WAIT_TIME_LIGHT hoursToSeconds(2)
#define STAGE1_WAIT_TIME_DARK hoursToSeconds(4.55)

#define STAGE2_TIME minutesToSeconds(3)
#define STAGE1_FILL_TIME  minutesToSeconds(2.5)

#define ENABLE_LIGHT_STAGE_SWITCH 1

#endif