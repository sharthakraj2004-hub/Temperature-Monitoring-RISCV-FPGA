/*****************************************************************************

 Project Name		: SDP - SOC Development Project
 Project Code		: ET1035
 Filename			: UART_ADC_Led_GPIO.c
 Purpose			: ADC and GPIO interface
 Description		: control led through ADC
 Author				: Sharthak Raj
    
 See LICENSE for license details.
******************************************************************************/

/**
 @file led_toggle_pgm.c
 @brief Main program to toggle the LED's
*/

#include "stdlib.h"
#include "config.h"
#include "gpio.h"
#include "uart.h"
#include "delay.h"
#include <stdio.h>

void main()
{
    int b0, b1, b2, b3;
    int value;

    uart_set_baud_rate(UART_0, 115200, 40000000);

    printf("\n\rGPIO ADC Receiver Started\n\r");

    while (1)
    {
        // Read GPIO bits
        b0 = pinRead(PIN_1);
        b1 = pinRead(PIN_2);
        b2 = pinRead(PIN_3);
        b3 = pinRead(PIN_4);

        // Reconstruct 4-bit value
        value =
            (b0 << 0) |
            (b1 << 1) |
            (b2 << 2) |
            (b3 << 3);

        printf("\n\rReceived Value = ");

	if(value >= 10)
	{
    		uart_putchar(UART_0, '1', 0);
    		uart_putchar(UART_0, '0' + (value - 10), 0);
	}
	else
	{
    		uart_putchar(UART_0, '0' + value, 0);
	}

        // LED control on PIN_8
        if (value > 13)
        {
            pinSet(PIN_8);
            printf("   LED ON");
        }
        else
        {
            pinClear(PIN_8);
            printf("   LED OFF");
        }

        delayMilliseconds(500);
    }
}
