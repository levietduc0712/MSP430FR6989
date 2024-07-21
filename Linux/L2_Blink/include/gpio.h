#ifndef __MSP430FR6989_GPIO_H__
#define __MSP430FR6989_GPIO_H__

#include <msp430.h>

// Define the GPIO_PORT for the MSP430FR6989
#define GPIO_PORT_P1                        1
#define GPIO_PORT_P2                        2
#define GPIO_PORT_P3                        3
#define GPIO_PORT_P4                        4
#define GPIO_PORT_P5                        5
#define GPIO_PORT_P6                        6
#define GPIO_PORT_P7                        7
#define GPIO_PORT_P8                        8
#define GPIO_PORT_P9                        9
#define GPIO_PORT_P10                       10

// Define the GPIO_PIN for the MSP430FR6989
#define GPIO_PIN0                           0x0001
#define GPIO_PIN1                           0x0002
#define GPIO_PIN2                           0x0004
#define GPIO_PIN3                           0x0008
#define GPIO_PIN4                           0x0010
#define GPIO_PIN5                           0x0020
#define GPIO_PIN6                           0x0040
#define GPIO_PIN7                           0x0080

// Define the GPIO_DIR for the MSP430FR6989
#define GPIO_DIR_INPUT                      0
#define GPIO_DIR_OUTPUT                     1

// Define the GPIO_OUT for the MSP430FR6989
#define GPIO_OUT_LOW                        0
#define GPIO_OUT_HIGH                       1

// Prototypes
void gpio_init(unsigned int port, unsigned int pin, unsigned int dir, unsigned int out);
void gpio_set(unsigned int port, unsigned int pin, unsigned int out);

#endif // __MSP430FR6989_GPIO_H__
