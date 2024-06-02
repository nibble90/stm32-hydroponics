#ifndef HEADER_FILE_CONSTANTS
#define HEADER_FILE_CONSTANTS

#include <stdint.h>

// Peripheral addresses start here
#define PERIPHERAL 0x40000000

// Config Settings
#define PUMP1_PIN 0
#define PUMP2_PIN 1
#define PUMP3_PIN 2
#define LDR_PIN 3

#define PUMP1_FILL_TIME 10 // max value is 5461 (seconds)
#define PUMP2_FILL_TIME 10000 // max value is 5461 (seconds)
#define PUMP3_FILL_TIME 10000 // max value is 5461 (seconds)

#endif