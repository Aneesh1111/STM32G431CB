#include <stdint.h>
#include <stm32g431xx.h>

#define LED_PIN 6


enum port_configuration_moder
{ 
  input_mode = 0,
  general_purpose_output_mode = 1,
  alternate_function_mode = 2,
  analog_mode = 3
};


int set_GPIOC_MODER ( int mode, enum port_configuration_moder configure ) 
{
    uint32_t GPIOC_prev = GPIOC->MODER;
    uint32_t mask = (3 << mode*2);

    GPIOC->MODER &= ~mask;
    GPIOC->MODER |= (configure << mode*2);
}


void main(void)
{
    RCC->AHB2ENR |= (1 << RCC_AHB2ENR_GPIOCEN_Pos);

    // do two dummy reads after enabling the peripheral clock, as per the errata
    volatile uint32_t dummy;
    dummy = RCC->AHB2ENR;
    dummy = RCC->AHB2ENR;

    int mode_num = 6;
    set_GPIOC_MODER( mode_num, general_purpose_output_mode );

    while(1)
    {
        GPIOC->ODR ^= (1 << LED_PIN);
        for (uint32_t i = 0; i < 1000000; i++);
    }
}
