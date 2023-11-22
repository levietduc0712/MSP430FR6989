//******************************************************************************
//  MSP430FR6989 - PushButton P1.1 and RED LED P1.0
//  Pull-up resistor: The pull-up resistor keeps the input signal high. When the button is pushed, the input signal is pulled low.
//  Description: Turn on the RED LED if the pushbutton P1.0 is pushed.
//
//               MSP430FR6989
//            -----------------
//        /|\|                 |
//         | |                 |
//         --|RST              |
//           |                 |
//     /|\   |                 |
//      --o--|P1.1         P1.0|-->LED
//           |                 |
//
//   Viet Duc
//   Nov 2023
//   Built with Code Composer Studio V10.2
//******************************************************************************
#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    // Configure GPIO
    P1DIR |= BIT0;                          // P1DIR |= 0x0001 <=> P1PIR |= 00000001. Set Pin 0 of Port 1 as an output.

    P1OUT |= BIT1;                          // Set output of Pin 1 - Port 1 is high
    P1REN |= BIT1;                          // Pull-up enable


    while(1)
    {
        while((BIT1 & P1IN) == 0)           // Check if P1.1 is pushed ? 00000010(BIT1) & 00000000 == 0 ?
        {
            P1OUT |= BIT0;                  // Turn on RED LED
        }
        P1OUT &= ~BIT0;                     // Turn off RED LED
    }
}
