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

void display_i2c_package (uint8_t line, i2c_package_t i2c_package);
void display_i2c_data    (i2c_package_t i2c_package);
void write_to_display    (char *string);

void update_display(void)
{
    display_i2c_data (I2C_PACKAGE);
    /* display_i2c_package(1, I2C_PACKAGE);
    display_i2c_package(2, MASKED_I2C_PACKAGE); */
}


void write_to_display (char* string)
{
    lcd_display_set_cursor(1,1);
    lcd_display_write_string(string);
}


void display_i2c_package (uint8_t line, i2c_package_t i2c_package)
{
    lcd_display_set_cursor(line, 1);
    lcd_display_write_string("add:  data:  I2C");
    lcd_display_set_cursor(line,5);
    lcd_display_write_char(i2c_package.addr);
    lcd_display_set_cursor(line,12);
    lcd_display_write_char(i2c_package.data.value[0]);
}


void display_i2c_data (i2c_package_t i2c_package)
{
    lcd_display_set_cursor(1, 1);
    lcd_display_write_string("-------------------------");
    lcd_display_set_cursor(2, 1);
    lcd_display_write_string("-------------------------");

    for(uint8_t i = 0; i2c_package.data.value[i]!='\0'; i++){
        lcd_display_set_cursor(1+(i/16), (i%16)+1);
        lcd_display_write_char(i2c_package.data.value[i]);
    }
    lcd_display_set_cursor(1,16);
    lcd_display_write_char('|');
    lcd_display_set_cursor(2,16);
    lcd_display_write_char('|');

}
