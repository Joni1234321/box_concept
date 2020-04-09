#include "global.h"
#include "interrupt.h"

void on_interrupt_i2c (void);
void on_interrupt_timer_0(void);

void __interrupt() interruptHandler()
{ 
    // I2C Read
    if (SSPIE && SSPIF){
        on_interrupt_i2c ();
    }
    
    // Timer
    if (T0IE && T0IF){
        on_interrupt_timer_0();
        T0IF = 0;
    }
}

void on_interrupt_timer_0 (void)
{
    
}

