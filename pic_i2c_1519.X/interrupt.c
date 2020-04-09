#include "global.h"
#include "interrupt.h"


void on_interrupt_timer_0 (void){
    
}

void __interrupt() interruptHandler(void)
{ 
    // Timer
    if (T0IE && T0IF){
        on_interrupt_timer_0();
        T0IF = 0;
    }
}

