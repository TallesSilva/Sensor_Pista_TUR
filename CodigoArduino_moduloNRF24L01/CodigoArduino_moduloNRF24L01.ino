
#include "nrf24le01Module.h"
#include "led_rgb.h"

#define UART_BAUDRATE       115200

//Endereços
#define BROADCAST_ADDRESS '0'
#define SENSOR_A_ADDRESS '1'

//Comandos
#define INICIA_TIMER_CMD 'I'
#define DESLIGA_TIMER_CMD 'D'
#define LER_COUNTER_CMD 'R'
#define MUDAR_LED_CMD 'L'
#define LER_BTN_FLAG_CMD 'B'
#define RESET_TIMER 'A'

//Variáveis
uint8_t sensor = '1';
uint8_t tempos[2];

led_rgb status_led(7, 6, 5); //R_pin,G_pin,B_pin
nrf24le01Module host_nrf(2, 4, 3); //IRQ, CE, CSN

unsigned long actual_millis, received_millis, sent_millis, requisitou_dado_millis, momento_para_req_s2;
void setup() {
  Serial.begin(UART_BAUDRATE);
  status_led.init();
  host_nrf.rf_init(host_nrf.ADDR_HOST, host_nrf.ADDR_HOST, 92, RF_DATA_RATE_2Mbps, RF_TX_POWER_0dBm); //RF Communication
  attachInterrupt(digitalPinToInterrupt(host_nrf.RFIRQ), rf_interrupt, FALLING); //Todo: put inside library
  piscas_iniciais_led();
}

void loop()
{
  int dado;
  actual_millis = millis();
  if (host_nrf.newPayload)
  {
    received_millis = actual_millis;
    host_nrf.newPayload = 0;
    status_led.apagar();
    //Serial.print(sensor); // envia um valor inteiro 1 ou 2 ou 3 ...
    //Serial.print(tempo);
    //Serial.print(tempo);
  }
  dado = 0;
  if (Serial.available())
    dado = Serial.read();
  switch (dado)
  {
    case 'I':   status_led.acender(LED_COLOR_GREEN);
      host_nrf.tx_buf[0] = BROADCAST_ADDRESS;
      host_nrf.tx_buf[1] = dado;
      host_nrf.TX_Mode_NOACK(2);
      break;

    case 'A':   status_led.acender(LED_COLOR_RED);
      host_nrf.tx_buf[0] = BROADCAST_ADDRESS;
      host_nrf.tx_buf[1] = dado;
      host_nrf.TX_Mode_NOACK(2);
      break;

    case 'R':   status_led.acender(LED_COLOR_BLUE);
      if (sensor == '1')
      {
        host_nrf.tx_buf[0] = '1';
        host_nrf.tx_buf[1] = dado;
        host_nrf.TX_Mode_NOACK(2);
        if (host_nrf.RX_OK)
        {
          status_led.apagar();
          status_led.acender(LED_COLOR_BLUE);
          tempos[0] = host_nrf.rx_buf[2];
          tempos[1] = host_nrf.rx_buf[3];

          Serial.write(host_nrf.rx_buf[0]); // Sensor
          Serial.write(tempos[0]); // HIGH Tempo
          Serial.write(tempos[1]); // LOW Tempo
        }
        sensor = '2';
      }
      if ( sensor == '2' )
      {
        host_nrf.tx_buf[0] = '2';
        host_nrf.tx_buf[1] = dado;
        host_nrf.TX_Mode_NOACK(2);
        if (host_nrf.RX_OK)
        {
          status_led.apagar();
          status_led.acender(LED_COLOR_BLUE);
          tempos[0] = host_nrf.rx_buf[2];
          tempos[1] = host_nrf.rx_buf[3];

          Serial.write(host_nrf.rx_buf[0]); // Sensor
          Serial.write(tempos[0]); // HIGH Tempo
          Serial.write(tempos[1]); // LOW Tempo
        }
        sensor = '3';
      }
      if ( sensor == '3' )
      {
        host_nrf.tx_buf[0] = '3';
        host_nrf.tx_buf[1] = dado;
        host_nrf.TX_Mode_NOACK(2);
        if (host_nrf.RX_OK)
        {
          status_led.apagar();
          status_led.acender(LED_COLOR_BLUE);
          tempos[0] = host_nrf.rx_buf[2];
          tempos[1] = host_nrf.rx_buf[3];

          Serial.write(host_nrf.rx_buf[0]); // Sensor
          Serial.write(tempos[0]); // HIGH Tempo
          Serial.write(tempos[1]); // LOW Tempo
        }
        sensor = '4';
      }
      if ( sensor == '4' )
      {
        host_nrf.tx_buf[0] = '4';
        host_nrf.tx_buf[1] = dado;
        host_nrf.TX_Mode_NOACK(2);
        if (host_nrf.RX_OK)
        {
          status_led.apagar();
          status_led.acender(LED_COLOR_BLUE);
          tempos[0] = host_nrf.rx_buf[2];
          tempos[1] = host_nrf.rx_buf[3];

          Serial.write(host_nrf.rx_buf[0]); // Sensor
          Serial.write(tempos[0]); // HIGH Tempo
          Serial.write(tempos[1]); // LOW Tempo
        }
        sensor = '5';
      }
      if ( sensor == '5' )
      {
        host_nrf.tx_buf[0] = '5';
        host_nrf.tx_buf[1] = dado;
        host_nrf.TX_Mode_NOACK(2);
        if (host_nrf.RX_OK)
        {
          status_led.apagar();
          status_led.acender(LED_COLOR_BLUE);
          tempos[0] = host_nrf.rx_buf[2];
          tempos[1] = host_nrf.rx_buf[3];

          Serial.write(host_nrf.rx_buf[0]); // SSensor
          Serial.write(tempos[0]); // HIGH Tempo
          Serial.write(tempos[1]); // LOW Tempo
        }
        sensor = '1';
      }
      break;
    default:    break;
  }
}
void rf_interrupt() {
  host_nrf.RF_IRQ();
}

void piscas_iniciais_led() {
  status_led.acender(LED_COLOR_RED); delay(100);
  status_led.apagar(); delay(100);
  status_led.acender(LED_COLOR_GREEN); delay(100);
  status_led.apagar(); delay(100);
  status_led.acender(LED_COLOR_BLUE); delay(100);
  status_led.apagar(); delay(100);
}


