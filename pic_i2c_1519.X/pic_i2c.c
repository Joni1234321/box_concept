#include <xc.h>

#include <stdint.h>
#include <math.h>

#include "global.h"
#include "config.h"
#include "init.h"
#include "interrupt.h"

#include "i2c_master.h"


void main() 
{
    // init
    init();
    
    DEBUG_PIN = 1;
    char data = '0';
    
    // main loop
    for(;;) {  
        __delay_ms (3000);
        i2c_master_send(0x30, data);
        DEBUG_PIN ^= 1;
        data++;
    }
    return;
}


