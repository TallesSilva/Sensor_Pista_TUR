/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision: 2513 $
 */

/** @file
 * @brief Enhanced ShockBurst Primary Transmitter example
 * @defgroup esb_ptx_example Enhanced ShockBurst Primary Transmitter (PTX) example
 * @{
 * @ingroup nrf_examples
 *
 * @brief This example sends packets continuously. The contents of P0 are
 * sent in the first payload byte (byte 0).
 *
 * The example shows the minimum required setup for transmitting packets to a
 * primary receiver (PRX) device.
 *
 * The following default radio parameters are being used:
 * - RF channel 2
 * - 2 Mbps data rate
 * - TX address 0xE7E7E7E7E7
 * - 1 byte CRC
 *
 * The project @ref esb_prx_example can be used as a counterpart for receiving the data.
 *
*/

//lint -e717
//lint -e714
//lint -e640

#ifdef MCU_NRF24LE1
#include "nrf24le1.h"
#include "hal_clk.h"
#endif

#ifdef MCU_NRF24LU1P
#include "nrf24lu1p.h"
#endif

#include <stdint.h>
#include <stdbool.h>
#include "hal_nrf.h"
#ifndef MCU_NRF24LU1P
#include "hal_clk.h" //lint !e322 !e7 "include file not found"
#endif

// Global variables
static bool volatile radio_busy;

void main(void)
{
  uint8_t payload[3];

  #ifdef MCU_NRF24LE1
  while(hal_clk_get_16m_source() != HAL_CLK_XOSC16M)
  {
    // Wait until 16 MHz crystal oscillator is running
  }
  #endif

  #ifdef MCU_NRF24LU1P
  // Enable radio SPI
  RFCTL = 0x10U;
  #endif

  // Enable the radio clock
  RFCKEN = 1U;

  // Enable RF interrupt
  RF = 1U;

  // Enable global interrupt
  EA = 1U;

  // Power up radio
  hal_nrf_set_power_mode(HAL_NRF_PWR_UP);

  for(;;)
  {
    // Put P0 contents in payload[0]
    payload[0] = ~P0;

    // Write payload to radio TX FIFO
    hal_nrf_write_tx_payload(payload, 3U);

    // Toggle radio CE signal to start transmission
    CE_PULSE();

    radio_busy = true;
    // Wait for radio operation to finish
    while (radio_busy)
    {
    }
  }
}

// Radio interrupt
NRF_ISR()
{
  uint8_t irq_flags;

  // Read and clear IRQ flags from radio
  irq_flags = hal_nrf_get_clear_irq_flags();

  switch(irq_flags)
  {
    // Transmission success
    case (1 << (uint8_t)HAL_NRF_TX_DS):
      radio_busy = false;
      // Data has been sent
      break;
    // Transmission failed (maximum re-transmits)
    case (1 << (uint8_t)HAL_NRF_MAX_RT):
      // When a MAX_RT interrupt occurs the TX payload will not be removed from the TX FIFO.
      // If the packet is to be discarded this must be done manually by flushing the TX FIFO.
      // Alternatively, CE_PULSE() can be called re-starting transmission of the payload.
      // (Will only be possible after the radio irq flags are cleared)
      hal_nrf_flush_tx();
      radio_busy = false;
      break;
    default:
      break;
  }
}
/** @} */
