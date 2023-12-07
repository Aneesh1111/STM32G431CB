#include <stdint.h>
#include <stm32g431xx.h>

#define LED_PIN 6

void main(void)
{
  RCC->AHB2ENR |= (1 << RCC_AHB2ENR_GPIOCEN_Pos);

  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = RCC->AHB2ENR;
  dummy = RCC->AHB2ENR;

  GPIOC->MODER = ~(1 << 13U);
  // GPIOC->MODER = 0xFFFFDFFF;
  
  while(1)
  {
    GPIOC->ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }

}