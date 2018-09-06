#include <Nordic\reg24le1.h>
#include <hal_delay.h>
#include <stdint.h>
#include <nRF-SPICommands.h>


#define LED P03
// habilitando timer1 no mode 1-16bits a 75us

void TRM0_IRQ() interrupt INTERRUPT_TMR0
{
	count++;
	TH0=0xFF; 
	TL0=0xFF;
	if(count == 1000000 ){ 
		LED = !(LED);
		count = 0;
	}
}

void start_T0(void) {
	TMOD=0x31;						// Select Timer 1 --> STOPPED, Timer 0 --> TIMER/16 bits
	TH0=0xFF; 
	TL0=0xFF;
	ET0=1;								// Active interrupt on Timer 0
	EA=1;									// Active all interrupts
	TR0=1;								// Timer 0 --> RUN
}

void setup()
{

	P0DIR = 0xFF;
	P1DIR = 0xFF;

	P0DIR &= ~(1<<3);
	
	start_T0();
	start_interrupt();

}

void loop()
{
		
}

void main()
{ 	int count;
	setup();
	while(1)
	{
	loop();
	}
}