#include "led_manipulation.h"

#include "driver/gpio.h"

uint32_t status_led_ms = 50;
void status_led_set(uint32_t ms)
{
	status_led_ms = ms;
}

void status_led_start()
{
    UBaseType_t uxHighWaterMark;
    uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
	while(1)
	{
		printf("status_led_start watermark: %d\n", uxHighWaterMark);
		gpio_set_level(2, 1);
		vTaskDelay(status_led_ms / portTICK_PERIOD_MS);
		gpio_set_level(2, 0);
		vTaskDelay(4000 / portTICK_PERIOD_MS);
        uxHighWaterMark = uxTaskGetStackHighWaterMark( NULL );
	}
}
