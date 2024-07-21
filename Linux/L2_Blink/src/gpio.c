#include <gpio.h>

void gpio_init(unsigned int port, unsigned int pin, unsigned int dir, unsigned int out)
{
    switch(port)
    {
        case GPIO_PORT_P1:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P1DIR |= pin;
            }
            else
            {
                P1DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P1OUT |= pin;
            }
            else
            {
                P1OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P2:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P2DIR |= pin;
            }
            else
            {
                P2DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P2OUT |= pin;
            }
            else
            {
                P2OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P3:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P3DIR |= pin;
            }
            else
            {
                P3DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P3OUT |= pin;
            }
            else
            {
                P3OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P4:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P4DIR |= pin;
            }
            else
            {
                P4DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P4OUT |= pin;
            }
            else
            {
                P4OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P5:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P5DIR |= pin;
            }
            else
            {
                P5DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P5OUT |= pin;
            }
            else
            {
                P5OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P6:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P6DIR |= pin;
            }
            else
            {
                P6DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P6OUT |= pin;
            }
            else
            {
                P6OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P7:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P7DIR |= pin;
            }
            else
            {
                P7DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P7OUT |= pin;
            }
            else
            {
                P7OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P8:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P8DIR |= pin;
            }
            else
            {
                P8DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P8OUT |= pin;
            }
            else
            {
                P8OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P9:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P9DIR |= pin;
            }
            else
            {
                P9DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P9OUT |= pin;
            }
            else
            {
                P9OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P10:
            if (dir == GPIO_DIR_OUTPUT)
            {
                P10DIR |= pin;
            }
            else
            {
                P10DIR &= ~pin;
            }
            if (out == GPIO_OUT_HIGH)
            {
                P10OUT |= pin;
            }
            else
            {
                P10OUT &= ~pin;
            }
            break;
    }
}

void gpio_set(unsigned int port, unsigned int pin, unsigned int out) {
    switch(port)
    {
        case GPIO_PORT_P1:
            if (out == GPIO_OUT_HIGH)
            {
                P1OUT |= pin;
            }
            else
            {
                P1OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P2:
            if (out == GPIO_OUT_HIGH)
            {
                P2OUT |= pin;
            }
            else
            {
                P2OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P3:
            if (out == GPIO_OUT_HIGH)
            {
                P3OUT |= pin;
            }
            else
            {
                P3OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P4:
            if (out == GPIO_OUT_HIGH)
            {
                P4OUT |= pin;
            }
            else
            {
                P4OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P5:
            if (out == GPIO_OUT_HIGH)
            {
                P5OUT |= pin;
            }
            else
            {
                P5OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P6:
            if (out == GPIO_OUT_HIGH)
            {
                P6OUT |= pin;
            }
            else
            {
                P6OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P7:
            if (out == GPIO_OUT_HIGH)
            {
                P7OUT |= pin;
            }
            else
            {
                P7OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P8:
            if (out == GPIO_OUT_HIGH)
            {
                P8OUT |= pin;
            }
            else
            {
                P8OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P9:
            if (out == GPIO_OUT_HIGH)
            {
                P9OUT |= pin;
            }
            else
            {
                P9OUT &= ~pin;
            }
            break;
        case GPIO_PORT_P10:
            if (out == GPIO_OUT_HIGH)
            {
                P10OUT |= pin;
            }
            else
            {
                P10OUT &= ~pin;
            }
            break;
    }
}
