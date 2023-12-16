#include <stdint.h>

// Reference Manual: Figure 2. Memory map
#define PERIPHERAL_BASE (0x40000000U)
#define AHB1_BASE (PERIPHERAL_BASE + 0x20000U)
#define AHB2_BASE (PERIPHERAL_BASE + 0x8000000U)
#define GPIOC_BASE (AHB2_BASE + 0x800U)
#define RCC_BASE (AHB1_BASE + 0x1000U)

// Reference Manual: 7.4.15 AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define RCC_AHB2ENR_OFFSET (0x4CU)
#define RCC_AHB2ENR ((volatile uint32_t*) (RCC_BASE + RCC_AHB2ENR_OFFSET))
#define RCC_AHB2ENR_GPIOCEN (0x02U)

// Reference Manual: 9.4.1 GPIO port mode register (GPIOx_MODER)
#define GPIO_MODER_OFFSET (0x00U)
#define GPIOC_MODER ((volatile uint32_t*) (GPIOC_BASE + GPIO_MODER_OFFSET))
#define GPIO_MODER_MODER6 (12U)

// Reference Manual: 9.4.6 GPIO port output data register (GPIOx_ODR)
#define GPIO_ODR_OFFSET (0x14U)
#define GPIOC_ODR ((volatile uint32_t*) (GPIOC_BASE + GPIO_ODR_OFFSET))

#define LED_PIN 6

void main(void)
{
  // *RCC_AHB2ENR |= (1 << RCC_AHB2ENR_GPIOCEN);
  *RCC_AHB2ENR = 0x00000004;

  // do two dummy reads after enabling the peripheral clock, as per the errata
  volatile uint32_t dummy;
  dummy = *(RCC_AHB2ENR);
  dummy = *(RCC_AHB2ENR);

  // *GPIOC_MODER |= (0 << GPIO_MODER_MODER6);
  *GPIOC_MODER = 0xFFFFDFFF;
  
  while(1)
  {
    *GPIOC_ODR ^= (1 << LED_PIN);
    for (uint32_t i = 0; i < 1000000; i++);
  }

}