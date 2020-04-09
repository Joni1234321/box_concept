#include "lcd_display.h"
#include "global.h"


void lcd_display_port(char a)
{
	if(a & 1)
		LCD_DISPLAY_D4 = 1;
	else
		LCD_DISPLAY_D4 = 0;

	if(a & 2)
		LCD_DISPLAY_D5 = 1;
	else
		LCD_DISPLAY_D5 = 0;

	if(a & 4)
		LCD_DISPLAY_D6 = 1;
	else
		LCD_DISPLAY_D6 = 0;

	if(a & 8)
		LCD_DISPLAY_D7 = 1;
	else
		LCD_DISPLAY_D7 = 0;
}

void lcd_display_cmd(char a)
{
    LCD_DISPLAY_RS = 0;             // => RS = 0
	lcd_display_port(a);
	LCD_DISPLAY_EN  = 1;             // => E = 1
    __delay_ms(4);
    LCD_DISPLAY_EN  = 0;             // => E = 0
}

void lcd_display_clear(void)
{
	lcd_display_cmd(0);
	lcd_display_cmd(1);
}

void lcd_display_set_cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		lcd_display_cmd(z);
		lcd_display_cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		lcd_display_cmd(z);
		lcd_display_cmd(y);
	}
}

void lcd_display_init(void)
{    
    lcd_display_port(0x00);
    __delay_ms(20);
    lcd_display_cmd(0x03);
    __delay_ms(5);
    lcd_display_cmd(0x03);
    __delay_ms(11);
    lcd_display_cmd(0x03);
    /////////////////////////////////////////////////////
    lcd_display_cmd(0x02);
    lcd_display_cmd(0x02);
    lcd_display_cmd(0x08);
    lcd_display_cmd(0x00);
    lcd_display_cmd(0x0C);
    lcd_display_cmd(0x00);
    lcd_display_cmd(0x06);
}

void lcd_display_write_char(char a)
{
    char temp,y;
    temp = a&0x0F;
    y = a&0xF0;
    LCD_DISPLAY_RS = 1;             // => RS = 1
    lcd_display_port(y>>4);             //Data transfer
    LCD_DISPLAY_EN = 1;
    __delay_us(40);
    LCD_DISPLAY_EN = 0;
    lcd_display_port(temp);
    LCD_DISPLAY_EN = 1;
    __delay_us(40);
    LCD_DISPLAY_EN = 0;
}

void lcd_display_write_string(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	   lcd_display_write_char(a[i]);
}

void lcd_display_shift_right(void)
{
	lcd_display_cmd(0x01);
	lcd_display_cmd(0x0C);
}

void lcd_display_shift_left(void)
{
	lcd_display_cmd(0x01);
	lcd_display_cmd(0x08);
}

