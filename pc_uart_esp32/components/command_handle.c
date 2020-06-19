#include "command_handle.h"

#include "commands/led_manipulation.h"


// Address of LCD display
#define I2C_LCD_ADDRESS 0x30

// Change speed of status LED
TaskHandle_t T_status_led = NULL;
static void handle_status_led (void* args);

// Write command
xQueueHandle Q_write;
static void handle_write(void* args);


void command_handle(uint8_t command, char* args)
{
	switch(command)
	{
	case CMD_PING:
		printf("CMD_PING is called \n");

		break;
	case CMD_STATUS:
		printf("CMD_STATUS is called \n");

		break;
	case CMD_CLOCK:
		printf("CMD_CLOCK is called \n");

		break;
	case CMD_STATUS_LED:
		printf("CMD_STATUS_LED is called \n");

		// Parse args as an integer
		xTaskNotify(T_status_led, atoi(args), eSetValueWithOverwrite);
		break;
	case CMD_WRITE:
		printf("CMD_WRITE is called \n");

		// Just send args
		xQueueSend(Q_write, &args, 100 / portTICK_PERIOD_MS);
		break;
	default:
		printf("UNDEFINED COMMAND %d \n", command);

		break;
	}
}

void command_handle_init (uint32_t priority)
{
	// Events
	// Queue size of 10, storing commands
	Q_write = xQueueCreate(10, CMD_MEMORY_SIZE);

	// Construct Tasks
	xTaskCreate(handle_status_led, "STATUS LED handler", 512, NULL, priority, &T_status_led);
	xTaskCreate(handle_write, "Write to LCD Display", 1024, NULL, priority, NULL);

	// Construct Sub functions
	status_led_start();
}

// Change status LED, light speed
static void handle_status_led (void* args)
{
	uint32_t ms_time;
	while(1)
	{
		if(xTaskNotifyWait(0xffffff, 0, &ms_time, portMAX_DELAY))
		{
			status_led_set(ms_time);
		}
	}
}

static void handle_write (void *args)
{
	while(1)
	{
		uint8_t* data;
    	if(xQueueReceive(Q_write, &data , portMAX_DELAY ))
        {
    		// Write data to I2C
    		size_t size = sizeof(data); //  works since each element is 1 byte long
    		i2c_write(I2C_LCD_ADDRESS, (uint8_t*)data, size);
        }
    	else
    	{
    		// No Data
    	}
	}
}

