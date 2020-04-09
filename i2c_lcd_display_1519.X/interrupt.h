#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <xc.h>
#include <stdint.h>

#include "i2c_interrupt.h" // I2C


typedef union {
    struct {
        unsigned update_lcd_display : 1;
    };
} int_flag_t;

volatile int_flag_t INT_FLAGS;   // GLOBAL INT FLAGS


#endif
