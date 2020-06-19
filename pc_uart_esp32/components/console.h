#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <stdio.h>
#include "string.h"

#include "freertos/FreeRTOS.h"
#include "freertos/Queue.h"
#include "freertos/task.h"

#include "driver/uart.h"

// Size of UART buffer
#define RX_BUF_SIZE 1024

// Init the console
void console_init(uint32_t command_memory_size, uint16_t buffer, uint16_t priority);

// Write
int8_t console_write(char* data);
// Read
xQueueHandle console_read_queue;


#endif
