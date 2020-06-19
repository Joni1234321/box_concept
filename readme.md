# box_concept

Dette er en række projekter der skal bruges som skabelon for mit BOX projekt

Målet er at lave følgende projekter:


**PIC->Display** 
- [x] Done 

PIC controller der kan vise noget på et LCD display
* lcd_display_1519

**PIC->I2C->PIC->Display**
- [x] Done 

PIC controller der kan sende I2C signal til en PIC controller der kan vise noget på et LCD display
* i2c_lcd_display_1519
* pic_i2c_1519

**PC->USB->PIC** 
- [-] Cancelled 

PIC controller der kan modtage og sende data gennem en UART port forbundet med computeren

** CHANGING PIC TO ESP32 **

**PC->USB->ESP32->I2C**
- [ ] Doing

ESP32 modul forbundet med pc gennem USB, og sender data videre til LCD skærm
*pc_uart_esp32

**PC->USB->ESP32->I2C->PIC->Display**
- [ ] Not Completed 

PC skal kunne sende et signal gennem en interface til en PIC controller der sender det videre til en anden controller der visualisere dataen
