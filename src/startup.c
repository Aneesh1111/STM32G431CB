#define SRAM_START (0x20000000U)
#define SRAM_SIZE (32U * 1024U)
#define SRAM_END (SRAM_START + SRAM_SIZE)
#define STACK_POINTER_INIT_ADDRESS (SRAM_END)

#include <stdint.h>
#define ISR_VECTOR_SIZE_WORDS 118  // Table 97. STM32G4 Series vector table 

extern uint32_t _etext, _sdata, _edata, _sbss, _ebss;
void main(void);
void reset_handler(void);
void default_handler(void);

/*
    - These names and the order is all from: Table 97. STM32G4 Series vector table 
*/

// Cortex-M system exceptions
void nmi_handler(void) __attribute__((weak, alias("default_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("default_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("default_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("default_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("default_handler")));
void svcall_handler(void) __attribute__((weak, alias("default_handler")));
void debug_monitor_handler(void) __attribute__((weak, alias("default_handler")));
void pendsv_handler(void) __attribute__((weak, alias("default_handler")));
void systick_handler(void) __attribute__((weak, alias("default_handler")));

// Reference Manual: STM32G4 interrupt handlers
void wwdg_handler(void) __attribute__((weak, alias("default_handler")));
void pvd_pvm_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_tamp_css_lse_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_wkup_handler(void) __attribute__((weak, alias("default_handler")));
void flash_handler(void) __attribute__((weak, alias("default_handler")));
void rcc_handler(void) __attribute__((weak, alias("default_handler")));
void exti0_handler(void) __attribute__((weak, alias("default_handler")));
void exti1_handler(void) __attribute__((weak, alias("default_handler")));
void exti2_handler(void) __attribute__((weak, alias("default_handler")));
void exti3_handler(void) __attribute__((weak, alias("default_handler")));
void exti4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch1_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch2_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch3_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch4_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch5_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch6_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch7_handler(void) __attribute__((weak, alias("default_handler")));
void adc1_2_handler(void) __attribute__((weak, alias("default_handler")));
void usb_hp_handler(void) __attribute__((weak, alias("default_handler")));
void usb_lp_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan1_it0_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan1_it1_handler(void) __attribute__((weak, alias("default_handler")));
void exti9_5_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_brk_tim15_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_up_tim16_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_trg_com_tim16_tim1_dir_tim1_idx_handler(void) __attribute__((weak, alias("default_handler")));
void tim1_cc_handler(void) __attribute__((weak, alias("default_handler")));
void tim2_handler(void) __attribute__((weak, alias("default_handler")));
void tim3_handler(void) __attribute__((weak, alias("default_handler")));
void tim4_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c1_er_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c2_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi1_handler(void) __attribute__((weak, alias("default_handler")));
void spi2_handler(void) __attribute__((weak, alias("default_handler")));
void usart1_handler(void) __attribute__((weak, alias("default_handler")));
void usart2_handler(void) __attribute__((weak, alias("default_handler")));
void usart3_handler(void) __attribute__((weak, alias("default_handler")));
void exti15_10_handler(void) __attribute__((weak, alias("default_handler")));
void rtc_alarm_handler(void) __attribute__((weak, alias("default_handler")));
void usb_wake_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_brk_tim8_terr_tim8_ierr_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_trg_com_tim8_dir_tim8_idx_handler(void) __attribute__((weak, alias("default_handler")));
void tim8_cc_handler(void) __attribute__((weak, alias("default_handler")));
void adc3_handler(void) __attribute__((weak, alias("default_handler")));
void fsmc_handler(void) __attribute__((weak, alias("default_handler")));
void lptim1_handler(void) __attribute__((weak, alias("default_handler")));
void tim5_handler(void) __attribute__((weak, alias("default_handler")));
void spi3_handler(void) __attribute__((weak, alias("default_handler")));
void uart4_handler(void) __attribute__((weak, alias("default_handler")));
void uart5_handler(void) __attribute__((weak, alias("default_handler")));
void tim6_dac_under_handler(void) __attribute__((weak, alias("default_handler")));
void tim7_dac_under_handler(void) __attribute__((weak, alias("default_handler")));
void dmac2_ch1_handler(void) __attribute__((weak, alias("default_handler")));
void dmac2_ch2_handler(void) __attribute__((weak, alias("default_handler")));
void dmac2_ch3_handler(void) __attribute__((weak, alias("default_handler")));
void dmac2_ch4_handler(void) __attribute__((weak, alias("default_handler")));
void dmac2_ch5_handler(void) __attribute__((weak, alias("default_handler")));
void adc4_handler(void) __attribute__((weak, alias("default_handler")));
void adc5_handler(void) __attribute__((weak, alias("default_handler")));
void ucpd1_handler(void) __attribute__((weak, alias("default_handler")));
void comp1_2_3_handler(void) __attribute__((weak, alias("default_handler")));
void comp4_5_6_handler(void) __attribute__((weak, alias("default_handler")));
void comp7_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_master_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_tima_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_timb_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_timc_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_timd_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_time_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_tim_flt_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void hrtim_timf_irqn_handler(void) __attribute__((weak, alias("default_handler")));
void crs_handler(void) __attribute__((weak, alias("default_handler")));
void sai_handler(void) __attribute__((weak, alias("default_handler")));
void tim20_brk_tim20_terr_tim20_ierr_handler(void) __attribute__((weak, alias("default_handler")));
void tim20_up_handler(void) __attribute__((weak, alias("default_handler")));
void tim20_trg_com_tim20_dir_tim20_idx_handler(void) __attribute__((weak, alias("default_handler")));
void tim20_cc_handler(void) __attribute__((weak, alias("default_handler")));
void fpu_handler(void) __attribute__((weak, alias("default_handler")));
void i2c4_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c4_er_handler(void) __attribute__((weak, alias("default_handler")));
void spi4_handler(void) __attribute__((weak, alias("default_handler")));
void aes_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan2_it0_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan2_it1_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan3_it0_handler(void) __attribute__((weak, alias("default_handler")));
void fdcan3_it1_handler(void) __attribute__((weak, alias("default_handler")));
void rng_handler(void) __attribute__((weak, alias("default_handler")));
void lpuart_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_ev_handler(void) __attribute__((weak, alias("default_handler")));
void i2c3_er_handler(void) __attribute__((weak, alias("default_handler")));
void dmamux_ovr_handler(void) __attribute__((weak, alias("default_handler")));
void quadspi_handler(void) __attribute__((weak, alias("default_handler")));
void dma1_ch8_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch6_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch7_handler(void) __attribute__((weak, alias("default_handler")));
void dma2_ch8_handler(void) __attribute__((weak, alias("default_handler")));
void cordic_handler(void) __attribute__((weak, alias("default_handler")));
void fmac_handler(void) __attribute__((weak, alias("default_handler")));

uint32_t isr_vector[ISR_VECTOR_SIZE_WORDS] __attribute__((section(".isr_vector"))) = {
    STACK_POINTER_INIT_ADDRESS,
    // Cortex-M system exceptions
    (uint32_t)&reset_handler,
    (uint32_t)&nmi_handler,
    (uint32_t)&hard_fault_handler,
    (uint32_t)&mem_manage_handler,
    (uint32_t)&bus_fault_handler,
    (uint32_t)&usage_fault_handler,
    0,
    0,
    0,
    0,
    (uint32_t)&svcall_handler,
    (uint32_t)&debug_monitor_handler,
    0,
    (uint32_t)&pendsv_handler,
    (uint32_t)&systick_handler,
    // STM32F410 interrupt handlers
    (uint32_t)&wwdg_handler,
    (uint32_t)&pvd_pvm_handler,
    (uint32_t)&rtc_tamp_css_lse_handler,
    (uint32_t)&rtc_wkup_handler,
    (uint32_t)&flash_handler,
    (uint32_t)&rcc_handler,
    (uint32_t)&exti0_handler,
    (uint32_t)&exti1_handler,
    (uint32_t)&exti2_handler,
    (uint32_t)&exti3_handler,
    (uint32_t)&exti4_handler,
    (uint32_t)&dma1_ch1_handler,
    (uint32_t)&dma1_ch2_handler,
    (uint32_t)&dma1_ch3_handler,
    (uint32_t)&dma1_ch4_handler,
    (uint32_t)&dma1_ch5_handler,
    (uint32_t)&dma1_ch6_handler,
    (uint32_t)&dma1_ch7_handler,
    (uint32_t)&adc1_2_handler,
    (uint32_t)&usb_hp_handler,
    (uint32_t)&usb_lp_handler,
    (uint32_t)&fdcan1_it0_handler,
    (uint32_t)&fdcan1_it1_handler,
    (uint32_t)&exti9_5_handler,
    (uint32_t)&tim1_brk_tim15_handler,
    (uint32_t)&tim1_up_tim16_handler,
    (uint32_t)&tim1_trg_com_tim16_tim1_dir_tim1_idx_handler,
    (uint32_t)&tim1_cc_handler,
    (uint32_t)&tim2_handler,
    (uint32_t)&tim3_handler,
    (uint32_t)&tim4_handler,
    (uint32_t)&i2c1_ev_handler,
    (uint32_t)&i2c1_er_handler,
    (uint32_t)&i2c2_ev_handler,
    (uint32_t)&i2c2_er_handler,
    (uint32_t)&spi1_handler,
    (uint32_t)&spi2_handler,
    (uint32_t)&usart1_handler,
    (uint32_t)&usart2_handler,
    (uint32_t)&usart3_handler,
    (uint32_t)&exti15_10_handler,
    (uint32_t)&rtc_alarm_handler,
    (uint32_t)&usb_wake_up_handler,
    (uint32_t)&tim8_brk_tim8_terr_tim8_ierr_handler,
    (uint32_t)&tim8_up_handler,
    (uint32_t)&tim8_trg_com_tim8_dir_tim8_idx_handler,
    (uint32_t)&tim8_cc_handler,
    (uint32_t)&adc3_handler,
    (uint32_t)&fsmc_handler,
    (uint32_t)&lptim1_handler,
    (uint32_t)&tim5_handler,
    (uint32_t)&spi3_handler,
    (uint32_t)&uart4_handler,
    (uint32_t)&uart5_handler,
    (uint32_t)&tim6_dac_under_handler,
    (uint32_t)&tim7_dac_under_handler,
    (uint32_t)&dmac2_ch1_handler,
    (uint32_t)&dmac2_ch2_handler,
    (uint32_t)&dmac2_ch3_handler,
    (uint32_t)&dmac2_ch4_handler,
    (uint32_t)&dmac2_ch5_handler,
    (uint32_t)&adc4_handler,
    (uint32_t)&adc5_handler,
    (uint32_t)&ucpd1_handler,
    (uint32_t)&comp1_2_3_handler,
    (uint32_t)&comp4_5_6_handler,
    (uint32_t)&comp7_handler,
    (uint32_t)&hrtim_master_irqn_handler,
    (uint32_t)&hrtim_tima_irqn_handler,
    (uint32_t)&hrtim_timb_irqn_handler,
    (uint32_t)&hrtim_timc_irqn_handler,
    (uint32_t)&hrtim_timd_irqn_handler,
    (uint32_t)&hrtim_time_irqn_handler,
    (uint32_t)&hrtim_tim_flt_irqn_handler,
    (uint32_t)&hrtim_timf_irqn_handler,
    (uint32_t)&crs_handler,
    (uint32_t)&sai_handler,
    (uint32_t)&tim20_brk_tim20_terr_tim20_ierr_handler,
    (uint32_t)&tim20_up_handler,
    (uint32_t)&tim20_trg_com_tim20_dir_tim20_idx_handler,
    (uint32_t)&tim20_cc_handler,
    (uint32_t)&fpu_handler,
    (uint32_t)&i2c4_ev_handler,
    (uint32_t)&i2c4_er_handler,
    (uint32_t)&spi4_handler,
    (uint32_t)&aes_handler,
    (uint32_t)&fdcan2_it0_handler,
    (uint32_t)&fdcan2_it1_handler,
    (uint32_t)&fdcan3_it0_handler,
    (uint32_t)&fdcan3_it1_handler,
    (uint32_t)&rng_handler,
    (uint32_t)&lpuart_handler,
    (uint32_t)&i2c3_ev_handler,
    (uint32_t)&i2c3_er_handler,
    (uint32_t)&dmamux_ovr_handler,
    (uint32_t)&quadspi_handler,
    (uint32_t)&dma1_ch8_handler,
    (uint32_t)&dma2_ch6_handler,
    (uint32_t)&dma2_ch7_handler,
    (uint32_t)&dma2_ch8_handler,
    (uint32_t)&cordic_handler,
    (uint32_t)&fmac_handler
};

void default_handler(void)
{
  while(1);
}

void reset_handler(void)
{
  // Copy .data from FLASH to SRAM
  uint32_t data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
  uint8_t *flash_data = (uint8_t*) &_etext;
  uint8_t *sram_data = (uint8_t*) &_sdata;
  
  for (uint32_t i = 0; i < data_size; i++)
  {
    sram_data[i] = flash_data[i];
  }

  // Zero-fill .bss section in SRAM
  uint32_t bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
  uint8_t *bss = (uint8_t*) &_sbss;

  for (uint32_t i = 0; i < bss_size; i++)
  {
    bss[i] = 0;
  }
  
  main();
}