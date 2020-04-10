#include "i2c_interrupt.h"

#include "interrupt.h"
#include "global.h"

void add_data_to_stack(i2c_command_t *command, uint8_t data);

void update_i2c_related_variables(i2c_package_t package);
void i2c_data_handler();

i2c_package_t current_package;
void on_interrupt_i2c (void) 
{
    SSPIF = 0;          // Clear Interrupt when Write or read address is received    
    CKP = 0;            // Clock stretch
    
    // ------------------------ COLLISION -------------------------//
    if ((SSPCONbits.SSPOV) || (SSPCONbits.WCOL)) //If overflow or collision
    {
      current_package.addr = SSPBUF;    // Read the previous value to clear the buffer
      SSPCONbits.SSPOV = 0; // Clear the overflow flag
      SSPCONbits.WCOL = 0;  // Clear the collision bit
      SSPCONbits.CKP = 1;
    }

    // --------------------------- WRITE --------------------------//
    if(!D_nA && !R_nW)  // Address
    { 
        current_package.addr = SSPBUF;  // Read data and clear
        while(BF);          // Wait for buffer to be cleared  
        CKP = 1;            // Stop stretching
    }
    if (D_nA && !R_nW)  // Data
    {
        current_package.data.value[current_package.data.index] = SSPBUF;  // Read data and clear
        current_package.data.index++;
        while(BF);          // Wait for buffer to be cleared
        CKP = 1;            // Stop stretching        
    }
    
    // --------------------------- READ ---------------------------//
    if(!D_nA && R_nW)   // Address
    { 
        current_package.addr = SSPBUF;  // Read data first    
        while(BF);          // Wait till data has been send
        SSPBUF = 0x54;      // Send a 'T' back
        while (SSPIF);      // Wait for nACK response received
        
        while (!ACKSTAT) {  // More data
            SSPBUF = 0x54;      // Send data
            while (SSPIF);      // Wait for nACK response received
        }
        CKP = 1;            // Stop stretching
    }
    if (D_nA && R_nW)   // Data
    {
        uint8_t bp_test_var = 0; // BREAKPOINT TEST VARRIABLE 
        CKP = 1;
    }
    
    // --------------------------- STOP ---------------------------//
    if (SSPSTATbits.P)         // Stop condition
    {
        // Update variables, and reset the current_package struct
        update_i2c_related_variables(current_package);
        current_package = I2C_PACKAGE_EMPTY;

        CKP = 1;
    }
}

void update_i2c_related_variables(i2c_package_t package)
{
    DEBUG_PIN ^= 1;

    MASKED_I2C_PACKAGE = I2C_PACKAGE; // Previous value
    I2C_PACKAGE = package;            // Current value
    
    INT_FLAGS.update_lcd_display = 1; // Update display whenever possible
}



void i2c_data_handler() 
{
    
}

void add_data_to_stack(i2c_command_t *command, uint8_t data)
{
    
}
