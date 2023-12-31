//******************************************************************************
//  MSP430FR6989 - Toggle P1.0 and P9.7
//
//           MSP430FR6989
//         ---------------
//     /|\|               |
//      | |               |
//      --|RST            |
//        |               |
//        |           P9.7|-->GREEN LED
//        |               |
//        |           P1.0|-->RED LED
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

    P9DIR |= BIT7;                          // P9DIR |= 0x0040 <=> P1PIR |= 01000000. Set Pin 7 of Port 9 as an output.
    P9OUT |= BIT7;                          // Set output of Pin 7 - Port 9 is high

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle RED LED
        __delay_cycles(100000);
        P9OUT ^= BIT7;                      // Toggle GREEN LED
        __delay_cycles(100000);
    }
}
