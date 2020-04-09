#ifndef __I2C_INTERRUPTS_H__
#define __I2C_INTERRUPTS_H__

#include <xc.h>
#include <stdint.h>

typedef struct {
    uint8_t addr;
    uint8_t data;
} i2c_package_t;

typedef struct {
    uint8_t command;
    uint8_t parameters[40];
}i2c_command_t;



volatile i2c_package_t I2C_PACKAGE;   // GLOBAL I2C VARS
volatile i2c_package_t MASKED_I2C_PACKAGE; // MASKED I2C VARS


void on_interrupt_i2c (void);


#endif
