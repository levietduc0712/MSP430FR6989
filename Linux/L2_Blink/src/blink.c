#include <gpio.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode to activate previously configured port settings
    gpio_init(GPIO_PORT_P1, GPIO_PIN0, GPIO_DIR_OUTPUT, GPIO_OUT_LOW);
    gpio_init(GPIO_PORT_P9, GPIO_PIN7, GPIO_DIR_OUTPUT, GPIO_OUT_LOW);

    while(1)
    {
        gpio_set(GPIO_PORT_P1, GPIO_PIN0, GPIO_OUT_HIGH);
        gpio_set(GPIO_PORT_P9, GPIO_PIN7, GPIO_OUT_HIGH);
        __delay_cycles(500000);
        gpio_set(GPIO_PORT_P1, GPIO_PIN0, GPIO_OUT_LOW);
        gpio_set(GPIO_PORT_P9, GPIO_PIN7, GPIO_OUT_LOW);
        __delay_cycles(500000);
    }
}
