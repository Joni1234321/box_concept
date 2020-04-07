#include <xc.h>

#include <stdint.h>
#include <math.h>

#include "global.h"
#include "config.h"
#include "init.h"
#include "interrupt.h"

#include "lcd_display.h"

lcd_display_t display;

void update_int_flags(void);
void main(void) 
{
    
    // init
    init();
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    
    lcd_display_init();
    
    lcd_display_clear();
    lcd_display_set_cursor(1,1);
    lcd_display_write_string("DET VIRKER");
    
    // main loop
    for(;;) {  
        

        
    }
    return;
}

void update_int_flags () 
{
    // Sleep
    if (INT_FLAGS.sleep){
        INT_FLAGS.sleep = 0;
    }
}
