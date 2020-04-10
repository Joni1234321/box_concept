#include <xc.h>
#include "init.h"

void init_oscillator(void);
void init_ports(void);
void init_i2c(void);
void init_interrupt(void);

// ADD OR REMOVE FROM HERE IF NOT WANTING TO INIT SOMETHING
void init (void) 
{
    init_oscillator();
    init_ports();
    init_i2c();
    init_interrupt();
}

void init_oscillator (void) 
{
    OSCCONbits.SCS1 = 1;         // Internal oscillator
    OSCCONbits.IRCF = 0b1110;    // 8 MHz
}

void res_ports(void);
void set_ports(void);
void init_ports (void)
{
    res_ports ();             // Reset ports
    set_ports ();             // Set ports
}
void res_ports (void) 
{
    // OUTPUT
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;

    // LOW
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;  
    LATD = 0x00;
    
    // NO ANALOG
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
}
// SET ALL INPUT PORTS HERE (TRISXbits = 1)
void set_ports (void) 
{ 
    
}

void init_i2c (void) 
{
    // Set I2C pins as input
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC4 = 1;
    
    // <3:0> = 0110 : Set as slave with 7-bit
    // <4>   = 1    : Enable Clock
    // <5>   = 1    : Enables I2C
    SSPCON1 = 0b00110110;

    // <0>  = 1     : Enable clock stretching
    SSPCON2 = 0x01;
     
    // <6> Enable stop bit interrupt PCIE
    SSPCON3 = 0b00000000;
    
    // Set slave address
    SSPADD = 0x30;
    
    // Disable the slew rate control since 100 kHz is used
    SSPSTAT = 0x80;
    
    // Enable Global interrupts
    INTCONbits.GIE = 1;
    
    // Enable peripheral interrupts
    INTCONbits.PEIE = 1;
    
    // Clear flag 
    SSPIF = 0;
    // Enable Synchronous serial port interrupts
    SSPIE = 1;
}

void init_interrupt_timer(void);
void init_interrupt (void)
{
    init_interrupt_timer ();
    
    // Enable interrupts
    INTCONbits.GIE = 1;   
}

// Interrupt timer activate
void init_interrupt_timer (void)
{
    // Prescaler enabled
    OPTION_REGbits.PSA = 0;
    // Prescaler 1 : 256 
    OPTION_REGbits.PS = 0b100;
    
    // Internal clock cycle
    OPTION_REGbits.TMR0CS = 0;
    
    // Increment on low to high transition on T0CKl pin
    OPTION_REGbits.TMR0SE = 0;
    
    
    // Enable timer
    T0IE = 1;
    // Reset timer counter 
    TMR0 = 0;
    
}
