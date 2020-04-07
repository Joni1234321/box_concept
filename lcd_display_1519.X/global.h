#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <xc.h>

// OSCILLATOR FREQUENCIES LOOKUP
#define _XTAL_FREQ 8000000
#define IPS  2000000 // IPS = (8 MHz / 4 cycles/instruction) = 2,000,000 instructions pr second

// INPUT  (PORTXbits)

// OUTPUT (LATXbits)
#define DEBUG_PIN LATCbits.LATC7
// LCD_DISPLAY START
#define LCD_DISPLAY_RS LATB1
#define LCD_DISPLAY_EN LATB0

#define LCD_DISPLAY_D4 LATA0
#define LCD_DISPLAY_D5 LATA1
#define LCD_DISPLAY_D6 LATA2
#define LCD_DISPLAY_D7 LATA3
// LCD_DISPLAY END

#endif