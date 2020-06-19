#ifndef _I2C_H_
#define _I2C_H_

#include <stdio.h>
#include "driver/i2c.h"
#include "esp_log.h"

esp_err_t i2c_init	(uint8_t sda, uint8_t scl);
esp_err_t i2c_write(uint32_t address, uint8_t *data, size_t size);
esp_err_t i2c_read(uint32_t address, uint8_t *data, size_t size);

#endif
