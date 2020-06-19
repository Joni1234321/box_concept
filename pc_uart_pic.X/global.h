#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <xc.h>

// OSCILLATOR FREQUENCIES LOOKUP
#define _XTAL_FREQ 8000000
#define IPS  2000000 // IPS = (8 MHz / 4 cycles/instruction) = 2,000,000 instructions pr second

// INPUT  (PORTXbits)

// OUTPUT (LATXbits)
#define DEBUG_PIN LATCbits.LATC7


#endif