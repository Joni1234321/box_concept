#ifndef __I2C_CLASSES_H__
#define __I2C_CLASSES_H__

#include <xc.h>
#include <stdint.h>

#define I2C_MAX_DATA 32  // Maximum amount of bytes that can be sent

typedef struct {
    uint8_t addr;
    struct {
        uint8_t value[I2C_MAX_DATA];   
        uint8_t index;                  
    } data;

} i2c_package_t;

const i2c_package_t I2C_PACKAGE_EMPTY; // Used to reset a package

volatile i2c_package_t I2C_PACKAGE;   // GLOBAL I2C VARS
volatile i2c_package_t MASKED_I2C_PACKAGE; // MASKED I2C VARS

typedef struct {
    uint8_t command;
    
    uint8_t parameters[I2C_MAX_DATA];
    uint8_t parameter_index;
    
}i2c_command_t;




#endif
