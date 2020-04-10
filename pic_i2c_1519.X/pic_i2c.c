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
    uint8_t* data = "Hej med dig :)  Meget sjovt";
    
    // main loop
    for(;;) {  
        DEBUG_PIN ^= 1;

        __delay_ms (3000);
        i2c_master_send(0x30, data);
    }
    return;
}


