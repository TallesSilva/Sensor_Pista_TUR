/* Copyright (c) 2009 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic 
 * Semiconductor ASA.Terms and conditions of usage are described in detail 
 * in NORDIC SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *              
 * $LastChangedRevision: 133 $
 */

/** @file
 * @brief Gazell Link Layer Device example
 * @defgroup gzll_device_example Gazell Link Layer Device example
 * @{
 * @ingroup nrf_examples
 *
 * @brief This example sends packets continuously. The contents of P0 are 
 * sent in the first payload byte (byte 0). 
 *
 *
 * Protocol parameters such as addresses and channels are specified 
 * in @ref gazell_examples/params/gzll_params.h. 
 *
 * The project @ref gzll_host_example can be used as a counterpart for receiving the data.
 * 
*/

//lint -e534

#include "gzll_mcu.h"
#include "gzll.h"

void main(void)
{
  uint8_t payload[GZLL_MAX_PAYLOAD_LENGTH];
  uint8_t packet_cnt = 0;
  uint8_t rx_packet_cnt = 0;
  uint8_t rx_packet_byte0 = 0;

  mcu_init();
  gzll_init();

  // Set P0 as output
  P0DIR = 0;    

  EA = 1;

  for(;;)
  {      
    // If gazell link layer idle
    if(gzll_get_state() == GZLL_IDLE)
    {
      if(gzll_rx_fifo_read(payload, NULL, NULL))
      {
        P0 = ~payload[0];
      }

      // Put P0 contents in payload[0]
      payload[0] = P2;
       
      // Transmits payload[] to pipe 0 address
      gzll_tx_data(payload, 1, 0);   
    }
  }  
}

/** @} */