//******************************************************************************
//  MSP430FR6989 - Toggle P1.0
//
//           MSP430FR6989
//         ---------------
//     /|\|               |
//      | |               |
//      --|RST            |
//        |               |
//        |           P1.0|-->LED
//
//   Viet Duc
//   Nov 2023
//   Built with Code Composer Studio V10.2
//******************************************************************************
#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // P1DIR |= 0x0001 <=> P1PIR |= 00000001. Set Pin 0 of Port 1 as an output.
    P1OUT |= BIT0;                          // Set output of Pin 0 - Port 1 is high

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        __delay_cycles(100000);
    }
}
