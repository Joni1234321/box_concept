#ifndef __LCD_DISPLAY_H__
#define	__LCD_DISPLAY_H__

#include <xc.h> 
#include <stdint.h>

typedef struct {
    union {
        struct {
            unsigned sleep : 1;
        };
    } int_flag_t;    
} lcd_display_t;

void lcd_display_init();

void lcd_display_clear();
void lcd_display_set_cursor(char a, char b);

void lcd_display_write_char(char a);
void lcd_display_write_string(char *a);

void lcd_display_shift_right();
void lcd_display_shift_left();

#endif	/* XC_HEADER_TEMPLATE_H */

