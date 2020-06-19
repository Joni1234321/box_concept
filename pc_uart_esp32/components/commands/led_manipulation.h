//LED MANIPULATION
#ifndef _LED_MANIPULATION_H_
#define _LED_MANIPULATION_H_

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"

void status_led_set(uint32_t ms);
void status_led_start();

#endif
