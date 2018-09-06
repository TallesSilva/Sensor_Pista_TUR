#include"reg24le1.h" // I/O header file for NRF24LE1
#include<stdint.h> // header file containing standard I/O functions
#include"hal_delay.h" // header file containing delay functions
#include"isrdef24le1.h" //header file containing Interrupt Service Routine definition for NRF24LE1
 
// main code
void main()
{
P0DIR = 0xf0; // make upper 4 bits of Port0 as input
P1DIR = 0;  // set Port1 as output
P1 = 0x00; // make all pins of Port1 low
IEN0 = 0x81; // enable interrupt from pin
INTEXP = 0x08; // enable INT0
while(1); // infinite loop, wait for interrupt
 
}
 
// Interrupt Service Routine
//EXT_INT0_ISR()
{
P1DIR = 0xff; // make all pins of Port1 high
delay_ms(1000); // delay of 1 second
P1DIR = 0x00; // make all pins of Port1 Low
delay_ms(1000);  // delay of 1 second
}