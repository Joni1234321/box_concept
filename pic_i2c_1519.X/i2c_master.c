#include "i2c_master.h"

void i2c_master_start(void);
void i2c_master_stop(void);

uint8_t i2c_master_write(unsigned data);

void i2c_master_wait(void);



// Sends data
void i2c_master_send (uint8_t i2c_add, uint8_t data)
{
    uint8_t i2c_address = i2c_add + 0; // Create the bus address and clear to write
    
    i2c_master_start();                     //Start condition
    
    if(i2c_master_write(i2c_add))   return; //7 bit address + Write
    if(i2c_master_write(data))      return; //Write data

    i2c_master_stop();                      //Stop condition

}
// Read data
void i2c_master_read (uint8_t i2c_add, uint8_t *data)
{
    uint8_t i2c_address = i2c_add + 1; // Create the bus address and set to read    
}


void i2c_master_start(void)
{
    SSPCON2bits.SEN = 1;    // Start
    while (SEN);            // Wait for start condition to complete 
    PIR1bits.SSPIF = 0;     // Clear SSP interrupt flag
}

void i2c_master_stop(void)
{
    SSPCON2bits.PEN = 1;    // Initiate stop condition
    while (PEN);            // Wait for Stop condition to complete
    
}

uint8_t i2c_master_write(unsigned data)
{
    SSPBUF = data;          // Send Data
    while (!SSPIF);         // Wait for Acknowledge
    PIR1bits.SSPIF = 0;     // Clear SSP interrupt flag
    if (SSPCON2bits.ACKSTAT) 
    {
        SSPCON2bits.PEN = 1;// Initiate stop condition
        while (PEN);        // Wait for Stop condition to complete
        return 1;           // Exit (No Acknowledge)
    }
    return 0;
}