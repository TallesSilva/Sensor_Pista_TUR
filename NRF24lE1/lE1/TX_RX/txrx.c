#include<Nordic\reg24le1.h>
#include<hal_delay.h>
#include<stdint.h>
#include<nRF-SPICommands.h>

void setup()
{
P0DIR = 0xFF;
P1DIR = 0xFF;

P0DIR &= ~(1<<3);
P0DIR &= ~(1<<6);

P1DIR |= 1<<4;
P0DIR |= 1<<2;
	
rf_init(ADDR_HOST, ADDR_HOST, 92, RF_DATA_RATE_2Mbps, RF_TX_POWER_0dBm);
}

void loop()
{
	if(P14 == 1)
	{
		
		tx_buf[0] = 'G';
		TX_Mode_NOACK(1);
		P03 =1;
		delay_ms(1000);
		P03 =0;
		delay_ms(1000);
		P03 =1;
		delay_ms(1000);
		P03 =0;
	}
	if(P14 == 0)
	{ 
		P03 =0;
	}
	if(P02 == 1)
	{	tx_buf[0] = 'R';
		TX_Mode_NOACK(1);
		sendString("oi");
		P06=1;
	  delay_ms(1000);
		P06=0;
	  delay_ms(1000);
	  P06=1;
	  delay_ms(1000);
		P06=0;
	  delay_ms(1000);
	}	
	if(P02 == 0)
	{	
		P06=0;
	}
	
	if(newPayload)
	{
		newPayload = 0;
		switch(rx_buf[0])
		{
			case 'G':
				P06 =1;
			break;
			case 'R':
				P03 =1;
			break;
			default:
				P06 = 1; P03 = 1;  delay_ms(500);
				P06 = 0; P03 = 0; delay_ms(500);
				break;
		}
	}
}

void main()
{ 	
	setup();
	while(1)
	{
	loop();
	}
}