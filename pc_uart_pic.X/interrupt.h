#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <xc.h>
#include <stdint.h>


typedef union {
    struct {
        unsigned sleep : 1;
    };
} int_flag_t;
volatile int_flag_t INT_FLAGS;   // GLOBAL INT FLAGS


#endif
