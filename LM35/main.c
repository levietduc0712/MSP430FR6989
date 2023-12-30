//******************************************************************************
//   MSP430FR6989 Demo - ADC12, Sample A10, Set P1.0 if temperature > 32 Celsius.
//
//   Description: A single sample is taken from the LM35 temperature sensor,
//   connected to ADC input A10, with reference is 3.3V. If the temperature
//   reading in Celsius from the LM35 sensor is greater than 32 degrees,
//   P1.0 is set; otherwise, it is reset.
//
//                MSP430FR6989
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//        >---|P9.2/A10     P1.0|-->LED
//            |(3.3V)           |
//
//******************************************************************************

#include <msp430.h>

void ADC_SETUP(void);                       // Used to setup ADC12 peripheral
int temp, deg = 0;
float temp1 = 0.0;

main()
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
    P1DIR = BIT0;                           // Set RED LED to output
    ADC_SETUP();                            // Sets up ADC peripheral

    while(1)
    {
        ADC12CTL0 = ADC12CTL0 | ADC12ENC;   // Enable conversion
        ADC12CTL0 = ADC12CTL0 | ADC12SC;    // Start conversion

        temp = ADC12MEM0;                   // Decimal Value

        temp1 = (temp*(3.3/4095))*100;

        if (temp1 > 32)
        {
            P1OUT ^= BIT0;                  // Turn on red LED
            __delay_cycles(100000);
        }
        else
        {
            P1OUT = 0x00;                   // Turn off red LED
        }
    }
}

//************************************************************************
//*          Configure Analog-to-Digital Converter peripheral            *
//************************************************************************
void ADC_SETUP(void)
{
    ADC12CTL0 = ADC12SHT0_2 | ADC12ON;      // Sampling time, S&H=16, ADC12 on
    ADC12CTL1 = ADC12SHP;                   // Use sampling timer (ADC12 Sample/Hold Pulse Mode)
    ADC12CTL2 = ADC12RES_2;                 // 12-bit conversion results
    ADC12MCTL0 = ADC12INCH_10;              // P9.2 is analog input (ADC12 Input Channel 10)
}
