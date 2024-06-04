#ifndef HEADER_FILE_CONSTANTS
#define HEADER_FILE_CONSTANTS

#include <stdint.h>
#include "typedefs.h"

// Peripheral addresses start here
#define PERIPHERAL 0x40000000

// Config Settings
#define PUMP1_PIN 8
#define PUMP2_PIN 9
#define PUMP3_PIN 7
#define LDR_PIN 0

#define STAGE1_WAIT_TIME_LIGHT 10 // max value is 5461 (seconds)
#define STAGE1_WAIT_TIME_DARK 10 // max value is 5461 (seconds)
// Stage 2 must be less time than stage 1
#define STAGE2_TIME 20 // max value is 5461 (seconds)

#define STAGE1_FILL_TIME 10

#define ENABLE_LIGHT_STAGE_SWITCH 1

#endif