#include<Nordic\reg24le1.h> // Registradores do nrf24le1

/**
 * Função de inicialização das funções que serão utilizadas
 */
void setup(){
    // Inicializa os pinos do Port 0 e Port 1 todos como entradas.
    P0DIR = 0xFF; P1DIR = 0xFF;
    // Configura o pino 3 do Port 0 como saída
    P0DIR &= ~(1 << 3);
}

/**
 * Está função é chamada repetidivamente.
 */
void loop(){
	if(P14 == 1)
	{
    P03 = 1;
	}
	else
	{
		P03 = 0;
	}
} 

/**
 * Função Main, indicando como funcionará o sitema.
 * Ele está simplificado para funcionar semelhante ao arduino.
 */
void main(){
    setup();
    while(1){
        loop();
    }
}