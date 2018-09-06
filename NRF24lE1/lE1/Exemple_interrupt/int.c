#include <Nordic\reg24le1.h>
#include <stdint.h>
#include <nRF-SPICommands.h>
#include <reg24le1.h>
#include <timer0.h>

#define LED P03

int cont=0;

void ISR(void) interrupt INTERRUPT_TMR0
{
		cont++;
		TH0= 0XFF;
		TL0= 0x9C;
		if(cont<=50000) 
		{
			LED = 1;
			delay_ms(500);
			LED = 0;
			delay_ms(500);
			LED = 1;
			delay_ms(500);
			LED = 0;
		}
}

int main(){
	P0DIR = 0xF7; //1111 0111
	TMOD=0x31;						// Select Timer 1 --> STOPPED, Timer 0 --> TIMER/16 bits
	TH0= 0XFF; 
	TL0= 0X9C;
	IEN0 = ~(0xF7); //habilitando interrupção para estouro do timer 1
	while(1){
	}
	
return 0;
}