//******************************************************************************
//   MSP430FR6989 Demo - ADC12, Sample A10, Set P1.0 if temperature > 32 Celsius.
//
//   Description: A single sample is taken from the LM35 temperature sensor,
//   connected to ADC input A10, with reference is 3.3V. If the temperature
//   reading in Celsius from the LM35 sensor is greater than 34 degrees,
//   P1.0 is set; otherwise, it is reset. This examples also configures the
//   LCD in 4-Mux mode and displays the temperature on a TI LCD
//
//          MSP-EXP430FR6989 Launchpad
//              -----------------
//          /|\|                 |
//           | |              XIN|--
//           --|RST              |  32768Hz
//             |             XOUT|--
//             |                 |
//             |             COM3|----------------|
//             |             COM2|---------------||
//    >--------|P9.2/A10     COM1|--------------|||
//             |             COM0|-------------||||
//             |                 |    -------------
//             |           Sx~Sxx|---| 1 2 3 4 5 6 |
//             |                 |    -------------
//             |                 |       TI LCD
//
//
//   Viet Duc
//   Dec 2023
//   Built with Code Composer Studio V10.2
//******************************************************************************

#include <msp430.h> 
#include "lcd.h"

void ADC_SETUP(void);                       // Used to setup ADC12 peripheral
int temp, num = 0, deg = 0;
float temp1 = 0.0;

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR = BIT0;                           // Set RED LED to output
    ADC_SETUP();                            // Sets up ADC peripheral
    Init_LCD();
    clearLCD();

    while(1)
    {
        ADC12CTL0 = ADC12CTL0 | ADC12ENC;   // Enable conversion
        ADC12CTL0 = ADC12CTL0 | ADC12SC;    // Start conversion

        temp = ADC12MEM0;                   // Decimal Value

        temp1 = (temp*(3.3/4095))*100;

        deg = temp1 * 100;

        if (temp1 > 34)
        {
            P1OUT = BIT0;                  // Turn on red LED
        }
        else
        {
            P1OUT = 0x00;                   // Turn off red LED
        }

        if (deg>=1000)
            showChar((deg/1000)%10 + '0',pos2);
        if (deg>=100)
            showChar((deg/100)%10 + '0',pos3);
        if (deg>=10)
            showChar((deg/10)%10 + '0',pos4);
        if (deg>=1)
            showChar((deg/1)%10 + '0',pos5);

        showChar('C',pos6);

        // Decimal point
        LCDMEM[pos3+1] |= 0x01;

        // Degree symbol
        LCDMEM[pos5+1] |= 0x04;

        __delay_cycles(1000000);

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
