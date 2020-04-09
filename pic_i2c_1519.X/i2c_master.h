#ifndef __I2C_MASTER_H__
#define	__I2C_MASTER_H__

#include <xc.h> 
#include <stdint.h>

void i2c_master_send (uint8_t i2c_add, uint8_t data);
void i2c_master_read (uint8_t i2c_add, uint8_t *data);


#endif	/* XC_HEADER_TEMPLATE_H */

