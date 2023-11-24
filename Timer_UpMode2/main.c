//******************************************************************************
//  MSP430FR6989 - Toggle P1.0 using TimerA
//
//  TimerA0 ConTroL Register (TA0CTL)
//  ___________________________________________________________________________________________________________
// |            Not Used                |   TASSEL    |   Not used  |      MC     |       Not used    |  TAIFG |
// |Bit15 Bit14 Bit13 Bit12 Bit11 Bit10 | Bit09 Bit08 | Bit07 Bit06 | Bit05 Bit04 | Bit03 Bit02 Bit01 |  Bit00 |
// |                                    |   0     1   |             |   0     1   |                   |        |
// |-----------------------------------------------------------------------------------------------------------|
//
//  Description: Explore the full potential of TA0CTL, a powerful 16-bit register with a maximum count of 65,536.
//  With each count approximately representing 0.25 microseconds (ACLK mode),
//  the default maximum time achievable is 1.6384 seconds.
//  However, this code will guide you through the process of extending this time limit.
//
//           MSP430FR6989
//         ---------------
//     /|\|    TimerA     |
//      | |               |
//      --|RST            |
//        |               |
//        |           P1.0|-->LED
//
//
//   Viet Duc
//   Nov 2023
//   Built with Code Composer Studio V10.2
//******************************************************************************
#include <msp430.h>

int main(void)
{
    unsigned int numoftimes = 0;            // How many times it count from 0 to 40,000

    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    // Configure GPIO
    P1DIR |= BIT0;                          // P1DIR |= 0x0001 <=> P1PIR |= 00000001. Set Pin 0 of Port 1 as an output.
    P1OUT |= BIT0;                          // Set output of Pin 0 - Port 1 is high

    TA0CCR0 = 50000;                        // Timer will count up from 0 to 50,000
    TA0CTL = TASSEL__ACLK | MC__UP;         // Set clock source is ACLK, UP mode (Timer counts up to TA0CCR0 <-> 50,000)
                                            // ACLK will count approximately once every 25 microseconds (or 25µs).
                                            // 50,000*25µs = 1.25s
                                            // TASSEL__ACLK <-> 0000 0001 0000 0000 binary
                                            // MC__UP <-> 0000 0000 0001 0000 binary
                                            // TASSEL__ACLK | MC__UP = 0000 0001 0001 0000 binary

    while(1)
    {
        if(TA0CTL & 0x0001)                 // Check if the timer has counted to 50,000
        {
            numoftimes += 1;
            TA0CTL &= ~0x0001;              // Count up from 0 to 50,000 again
            if(numoftimes == 3){            // Check if the timer has counted to 150,000 approx. 1.25s x 3 = 3.75s
                P1OUT ^= BIT0;              // Toggle RED LED
                numoftimes = 0;             // Reset the variable to check the number of times again
            }
        }
    }
}
