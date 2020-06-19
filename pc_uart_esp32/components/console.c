#include "console.h"

// Queue
xQueueHandle console_write_queue;

static void console_tx(void* args);
static void console_rx(void* args);

void console_init(uint32_t command_memory_size, uint16_t buffer, uint16_t priority)
{

	// Construct
	console_write_queue = xQueueCreate(buffer, command_memory_size);
	console_read_queue 	= xQueueCreate(buffer, command_memory_size);

	// UART CONFIG
	const uart_config_t uart_config = {
	        .baud_rate = 115200,
	        .data_bits = UART_DATA_8_BITS,
	        .parity = UART_PARITY_DISABLE,
	        .stop_bits = UART_STOP_BITS_1,
	        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
	    };

	// We won't use a buffer for sending data.
	uart_driver_install(UART_NUM_0, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
	uart_param_config(UART_NUM_0, &uart_config);

	// Create tasks
	xTaskCreate(console_rx, "Read from console"	, 4024*2, NULL, priority, NULL);
	xTaskCreate(console_tx, "Write to console"	, 4024*2, NULL, priority, NULL);
}

// Write to console
int8_t console_write(char* data)
{
	return xQueueSend(console_write_queue, &data, 100 / portTICK_PERIOD_MS);
}

// THREAD, write to console
static void console_tx(void* args)
{
    while (1) {
    	char* data;
    	if(xQueueReceive(console_write_queue, &data , portMAX_DELAY ))
        {
			const int len = strlen(data);
			uart_write_bytes(UART_NUM_0, data, len);
        }
    	else
    	{
    		// No Data
    	}
    }
}

inline size_t u_strlen(unsigned char * array)
{
    return strlen((const char*)array);
}

// THREAD, read from uart
static void console_rx(void *arg)
{
	// Buffer
	uint8_t* data = (uint8_t*) malloc(RX_BUF_SIZE+1);
    while (1) {
        const int rxBytes = uart_read_bytes(UART_NUM_0, data, RX_BUF_SIZE, 1000 / portTICK_RATE_MS);
        if (rxBytes > 0) {
            data[rxBytes] = 0;

            int ok = xQueueSend(console_read_queue, &data, 100 / portTICK_PERIOD_MS);
            // Process read bytes
            if(ok)
            {
            	// Send to queue
            	printf("Console Received Message\n");

            }
            else
            {
            	// Queue overflow
            	printf("nothing to push\n");
            }
        }
    }
    free(data);
}



