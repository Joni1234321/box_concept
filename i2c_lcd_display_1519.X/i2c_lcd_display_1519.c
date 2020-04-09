#include <xc.h>

#include <stdint.h>
#include <math.h>

#include "global.h"
#include "config.h"
#include "init.h"
#include "interrupt.h"

#include "lcd_display.h"

lcd_display_t display;

void update_if_flag_set (void);
void main() 
{
    // init
    init();
    
    lcd_display_init();
    
    lcd_display_clear();
    lcd_display_set_cursor(1,1);
    lcd_display_write_string("Waiting ...");
    
    // main loop
    for(;;) {  
        update_if_flag_set();
    }
    return;
}

void update_display (void);
void update_if_flag_set (void)
{
    if (INT_FLAGS.update_lcd_display){
        INT_FLAGS.update_lcd_display = 0;
        update_display();
    }
}

void display_i2c_data (uint8_t line, i2c_package_t data);
void update_display(void)
{
    // lcd_display_clear();
    display_i2c_data(1, I2C_PACKAGE);
    display_i2c_data(2, MASKED_I2C_PACKAGE);
}

void display_i2c_data (uint8_t line, i2c_package_t i2c_package)
{
    lcd_display_set_cursor(line, 1);
    lcd_display_write_string("add:  data:  I2C");
    lcd_display_set_cursor(line,5);
    lcd_display_write_char(i2c_package.addr);
    lcd_display_set_cursor(line,12);
    lcd_display_write_char(i2c_package.data);
}
