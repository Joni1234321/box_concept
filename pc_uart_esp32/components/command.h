#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <stdio.h>
#include "commands/index.h"

void command_init(uint32_t priority);
void command_write(uint8_t command, char* args);


#endif
