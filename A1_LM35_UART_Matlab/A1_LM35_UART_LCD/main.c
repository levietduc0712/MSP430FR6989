#include <msp430.h>
#include <stdio.h>
#include "lcd.h"

#define ENABLE_PINS 0xFFFE
#define UART_CLK_SEL 0x0080
#define BR0_FOR_9600 0x34
#define BR1_FOR_9600 0x00
#define CLK_MOD 0x4911

void select_clock_signals(void);
void assign_pins_to_uart(void);
void use_9600_baud(void);
void sendString(const char *str);
void sendFloat(float value);

void ADC_SETUP(void);                       // Used to setup ADC12 peripheral
int temp, num = 0, deg = 0;
float temp1 = 0.0;

int main()
{
    WDTCTL = WDTPW | WDTHOLD;
    PM5CTL0 = ENABLE_PINS;
    P1DIR = BIT0;                           // Set RED LED to output

    ADC_SETUP();                            // Sets up ADC peripheral
    Init_LCD();
    clearLCD();
    select_clock_signals();
    assign_pins_to_uart();
    use_9600_baud();


    while (1)
    {
        ADC12CTL0 = ADC12CTL0 | ADC12ENC;   // Enable conversion
        ADC12CTL0 = ADC12CTL0 | ADC12SC;    // Start conversion

        temp = ADC12MEM0;                   // Decimal Value

        temp1 = (temp*(3.3/4095))*100;

        deg = temp1 * 100;

        if (temp1 > 34)
        {
            P1OUT = BIT0;                  // Turn on red LED
            LCDM3 |= 0x01;                 // Set Exclamation symbol
            LCDBM3 |= 0x01;
        }
        else
        {
            P1OUT = 0x00;                   // Turn off red LED
            LCDM3 &= ~0x01;                 // Clear Exclamation symbol
            LCDBM3 &= ~0x01;
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

        sendFloat(temp1);
        sendString("\n");

        // Add a delay or other processing as needed
        __delay_cycles(5000000);
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
    ADC12MCTL0 = ADC12INCH_14;              // P9.6 is analog input (ADC12 Input Channel 14)
}

void sendString(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        UCA0TXBUF = str[i++];
        while (!(UCA0IFG & UCTXIFG));
    }
}

void sendFloat(float value)
{
    int intValue = (int)(value * 100);
    char buffer[10];  // Assuming a 32-bit integer, reserve enough space

    sprintf(buffer, "%d.%d", (intValue/100),(intValue%100));

    int i = 0;
    while (buffer[i] != '\0')
    {
        UCA0TXBUF = buffer[i++];
        while (!(UCA0IFG & UCTXIFG));
    }
}

void select_clock_signals(void)
{
    CSCTL0 = 0xA500;
    CSCTL1 = 0x0046;
    CSCTL2 = 0x0133;
    CSCTL3 = 0x0000;
}

void assign_pins_to_uart(void)
{
//    P4SEL1 = 0x00;
//    P4SEL0 = BIT3 | BIT2;

    P2SEL1 = 0x00;
    P2SEL0 = BIT1 | BIT0;

}

void use_9600_baud(void)
{
    UCA0CTLW0 = UCSWRST;
    UCA0CTLW0 = UCA0CTLW0 | UART_CLK_SEL;
    UCA0BR0 = BR0_FOR_9600;
    UCA0BR1 = BR1_FOR_9600;
    UCA0MCTLW = CLK_MOD;
    UCA0CTLW0 = UCA0CTLW0 & (~UCSWRST);
}
