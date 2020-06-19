#ifndef _COMMAND_HANDLE_H_
#define _COMMAND_HANDLE_H_

/// THIS HERE IS A MODIFIABLE FILE, USE IT TO SUIT YOUR PROGRAM

#include <stdio.h>

#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/task.h"
#include "FreeRTOS/semphr.h"

#include "i2c.h"
#include "commands/index.h"

void command_handle_init ();
void command_handle(uint8_t command, char* args);

#endif
