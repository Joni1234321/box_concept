// This file contains commands

#include "command.h"
#include "console.h"
#include "command_handle.h"

// Prototypes
static void command_process(void *args);

// Init command module
void command_init(uint32_t priority)
{
	// Create console, command size of
	console_init(CMD_TOTAL_SIZE, 10, priority);

	// Create tasks
	xTaskCreate(command_process, "Process the tasks from console",  1024*2, NULL, priority + 10, NULL);
}

// Send command through console
void command_write(uint8_t command, char* args)
{
	// Declare size of string
	char data[CMD_TOTAL_SIZE];

	// Parse arguments to command format [CMD:ARGS]
	itoa(command, data, 16); 	// Convert to hex
	strcat(data, ":");			// Add seperator
	strcat(data, args);			// Add arguments

	// Send command
	console_write(data);
}

// THREAD, read the command from xQueue
static void command_process(void *args)
{
	while(1)
	{
		char* data;
		if(xQueueReceive(console_read_queue, &data, portMAX_DELAY))
		{
			// Deconstruction of command
			char* command = strtok(data, ":");

			// Process command
			command_handle(atoi(command), strtok(NULL, ":"));
		}
		else
		{
			// No data (Timeout)
		}
	}
}

