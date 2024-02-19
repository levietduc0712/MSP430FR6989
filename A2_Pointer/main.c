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
//   Feb 2024
//   Built with Code Composer Studio V12.6
//******************************************************************************

#include <msp430.h> 

// Declare a volatile pointer variable named P1OUT_PTR, pointing to an unsigned integer, and assign the address 0x0202 to it.
volatile unsigned int *P1OUT_PTR = (volatile unsigned int*)0x0202;

// Declare a volatile pointer variable named P1DIR_PTR, pointing to an unsigned integer, and assign the address 0x0204 to it.
volatile unsigned int *P1DIR_PTR = (volatile unsigned int*)0x0204;

// Declare a volatile pointer variable named P9OUT_PTR, pointing to an unsigned integer, and assign the address 0x0282 to it.
volatile unsigned int *P9OUT_PTR = (volatile unsigned int*)0x0282;

// Declare a volatile pointer variable named P9DIR_PTR, pointing to an unsigned integer, and assign the address 0x0284 to it.
volatile unsigned int *P9DIR_PTR = (volatile unsigned int*)0x0284;

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer

    // Configure GPIO


    *P1DIR_PTR = 0x0001;                    // Set Pin 0 of Port 1 as an output.
    *P9DIR_PTR = 0x0080;                    // Set Pin 7 of Port 9 as an output.

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        *P1OUT_PTR = 0x0001;                // Turn on RED LED
        __delay_cycles(100000);
        *P1OUT_PTR = 0x0000;                // Turn off RED LED
        __delay_cycles(100000);

        *P9OUT_PTR = 0x0080;                // Turn on GREEN LED
        __delay_cycles(100000);
        *P9OUT_PTR = 0x0000;                // Turn off GREEN LED
        __delay_cycles(100000);
    }
}
