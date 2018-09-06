#include <timer0.h>
#include <reg24le1.h>
#include <hal_delay.h>	

#define LED P03 

EXT_INT0_ISR()  { 
LED = !LED;
}
void main()
{	IEN0 = 0x00;
	TCON = 0x20;
	TMOD = 0x31;
	IEN0 = 0x02;
	TH0 = 0x00;
	TL0 = 0x00;
	TR0 = 1;
	LED = 1;
	while(1)
	{
	}
}