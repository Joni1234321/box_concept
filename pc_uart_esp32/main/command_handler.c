// STD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pins
#define SDA	26	//18
#define SCL	27	//19


// ESP
#include "esp_system.h"
#include "esp_spi_flash.h"

// freeRTOS
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/event_groups.h"

// GPIO
#include "driver/gpio.h"

// Custom files
#include "../components/i2c.h"
#include "../components/command.h"
#include "../components/command_handle.h"

void setup();
void init_components();


void app_main()
{
	setup();
}

#define PRIORITY_COMMAND 			100
#define PRIOIRTY_COMMAND_HANDLER 	200

void init_components()
{
	i2c_init(SDA, SCL);
	command_init(PRIORITY_COMMAND);
	command_handle_init(PRIOIRTY_COMMAND_HANDLER);
}

#define LED1 2
#define LED2 4
void setup()
{
	gpio_set_direction(LED1, GPIO_MODE_OUTPUT);
	gpio_set_direction(LED2, GPIO_MODE_OUTPUT);

	init_components();

	command_write(CMD_STATUS, "ready");
}
