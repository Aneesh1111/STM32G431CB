#include <stdint.h>

// Reference Manual: Figure 2. Memory map
#define PERIPHERAL_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BASE + 0x20000U)
#define AHB2_BASE (PERIPHERAL_BASE + 0x8000000U)
#define GPIOA_BASE (AHB2_BASE + 0x0U)
#define RCC_BASE (AHB1_BASE + 0x1000U)

// Reference Manual: 7.4.15 AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_AHB1ENR_OFFSET (0x4CU)
#define RCC_AHB1ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB1ENR_OFFSET))
#define RCC_AHB1ENR_GPIOAEN (0x00U)

// Reference Manual: 9.4.1 GPIO port mode register (GPIOx_MODER)
#define GPIO_MODER_OFFSET (0x00U)
#define GPIOA_MODER ((volatile uint32_t*) (GPIOA_BASE + GPIO_MODER_OFFSET))
#define GPIO_MODER_MODER9 (18U)

// Reference Manual: 9.4.6 GPIO port output data register (GPIOx_ODR)
#define GPIO_ODR_OFFSET (0x14U)
#define GPIOA_ODR ((volatile uint32_t*) (GPIOA_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 9

void main(void)
{
  *RCC_AHB1ENR |= (1 << RCC_AHB1ENR_GPIOAEN);

  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = *(RCC_AHB1ENR);
  dummy = *(RCC_AHB1ENR);

  *GPIOA_MODER |= (1 << GPIO_MODER_MODER9);
  
  while(1)
  {
    *GPIOA_ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }

}