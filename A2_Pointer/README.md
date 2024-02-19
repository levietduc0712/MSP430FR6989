## Description
This code demonstrates how to manipulate GPIO (General Purpose Input/Output) pins on an MSP430 microcontroller using memory-mapped registers.

## Code Overview
- The code initializes volatile pointer variables (`P1OUT_PTR`, `P1DIR_PTR`, `P9OUT_PTR`, `P9DIR_PTR`) to access the control registers of GPIO pins.
- The memory addresses of these registers are directly assigned to the pointer variables.
- The main function configures pins 0 of port 1 and 7 of port 9 as output pins using the pointers `P1DIR_PTR` and `P9DIR_PTR`, respectively.
- The code continuously toggles the states of LEDs connected to these pins in an infinite loop.
