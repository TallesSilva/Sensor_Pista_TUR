#include<Nordic\reg24le1.h>
#include<stdint.h>
#include<nRF-SPICommands.h>
#include<timer0.h>
#include<hal_delay.h>

//Endere?os
#define BROADCAST_ADDRESS '0'
#define MY_SUB_ADDRESS '5'

//Comandos
#define INICIA_TIMER_CMD 'I'
#define DESLIGA_TIMER_CMD 'D'
#define LER_COUNTER_CMD 'R'
#define LER_BTN_FLAG_CMD 'B'
#define PING_ECO_CMD 'E'
#define RESET_TIMER 'A'

//Pinos
#define LED_SISTEMA_ON P03
#define LED_ENVIO P05
#define LED_TIMER_ON P12
#define LED_AJUSTE P13
#define SENSOR P14


//Vari?veis
uint8_t btn_passou = 0;
uint16_t tempo1 = 0;
uint8_t i = 0;

void setup(){
	P0DIR = 0xD7; //1101 0111 - Pinos do Port0
	P1DIR = 0xF3; //1111 0011 - Pinos do Port1

	rf_init(ADDR_HOST,ADDR_HOST, 92,
				  RF_DATA_RATE_2Mbps, RF_TX_POWER_0dBm); //Configura a rede RF

	setup_T0_ticks(6666, 60006);	//Configura o timer como descrito:
																//a cada 5ms o timer estoura (4.9995)
																//60 006 vezes ? o maximo que pode repetir este tempo
																//4.9995 * 60 006 = 300 segundos = 5 minutos
	prepare_T0(); //Ativa as interrup??es e deixa o timer pronto para ser iniciado

	//Pisca os Leds Indicando que o Dispositivo foi iniciado
	LED_ENVIO = 1; delay_ms(100); LED_ENVIO = 0; delay_ms(100);
	LED_ENVIO = 1; delay_ms(100); LED_ENVIO = 0; delay_ms(100);
	//Manda uma msg indicando que esta ON
	LED_SISTEMA_ON = 1;
}

void avalia_comando(){
		switch(rx_buf[1]){
			case RESET_TIMER:
				timer_count = 0;
				tempo1 = 0;
				LED_TIMER_ON = 0;
				break;
			case INICIA_TIMER_CMD:
				timer_count = 0;
				tempo1 = 0;
				TR0=1; // Timer0 --> RUN
				tx_buf[0] = MY_SUB_ADDRESS;
				tx_buf[1] = 'o';
				tx_buf[2] = 'n';
				TX_Mode_NOACK(3);
				LED_TIMER_ON = 1;
				break;
			case DESLIGA_TIMER_CMD:
				TR0=0; // Timer0 --> STOP
				tempo1 = 0;
				timer_count = 0;
				LED_TIMER_ON = 0;
				break;
			case LER_COUNTER_CMD:
				tx_buf[0] = MY_SUB_ADDRESS;
				tx_buf[1] = LER_COUNTER_CMD;
				tx_buf[2] = (uint8_t) (tempo1 >> 8); //msb
				tx_buf[3] = (uint8_t) (tempo1); //lsb
				TX_Mode_NOACK(4);
				LED_ENVIO=!LED_ENVIO;
				break;
			case PING_ECO_CMD:
				tx_buf[0] = MY_SUB_ADDRESS;
				for(i=1; i<payloadWidth; i++){
					tx_buf[i] = rx_buf[i];
				}
				TX_Mode_NOACK(payloadWidth);
				break;
			default:
				break;
	}
}

void main(){
	setup();
	while(1){
		LED_AJUSTE = SENSOR;
		if(SENSOR){
			btn_passou = 1;
			tempo1 = timer_count;
		}
		if(newPayload){
			newPayload = 0; sta = 0;
			if(rx_buf[0]==BROADCAST_ADDRESS){ //Se for uma mensagem para todo mundo
				avalia_comando();
			} else if(rx_buf[0]==MY_SUB_ADDRESS){ //Se for uma mensagem para o sensor
				avalia_comando();
			}
		}
	}
}

/**************************************************/
/********************TIMER*************************/
void TMR0_IRQ(void) interrupt INTERRUPT_TMR0
{
	if(!NOVT0)
	{
		timer_count++; // Acumula os tempos
    if(timer_count >= initial_timer_count){
        timer_elapsed = 1;
        timer_count = 0; // Reseta o contador
    }
		TH0= NBT0H;
		TL0= NBT0L;
	}
}
