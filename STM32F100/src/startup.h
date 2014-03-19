/*
 ********************************************************************************
 ** File:  startup.h
 **
 ** Description:
 ** Header file for startup.c
 ********************************************************************************
 ** DJB 11/17/13 Created
 ********************************************************************************
 */

#ifndef ___STARTUP_H___
#define ___STARTUP_H___

//------------------------------------------------------------------------------
//Defines
//None

//------------------------------------------------------------------------------
//Enumerations
//None

//------------------------------------------------------------------------------
//Structures
//None

//------------------------------------------------------------------------------
//Prototypes
//Default handlers:
//When the application defines a handler, with the same name, this will
//automatically take precedence over these weak definitions.
void reset_handler(void);
extern void nmi_handler(void) __attribute__((weak));
extern void hardfault_handler(void) __attribute__((weak));
extern void memmanage_handler(void) __attribute__((weak));
extern void busfault_handler(void) __attribute__((weak));
extern void usagefault_handler(void) __attribute__((weak));
extern void svc_handler(void) __attribute__((weak));
extern void debugmon_handler(void) __attribute__((weak));
extern void pendsv_handler(void) __attribute__((weak));
extern void systick_handler(void) __attribute__((weak));

//Specific IRQ handlers:
//These are aliased to the int_default_handler, which is a 'forever' loop.  When
//the application defines a handler, with the same name, this will automatically
//take precedence over these weak definitions.
extern void int_default_handler(void) __attribute__((weak));
extern void window_watchdog_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void pvd_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tamper_stamp_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void rtc_wakeup_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void flash_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void rcc_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti0_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti4_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel4_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel5_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel6_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma1_channel7_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void adc1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti9_5_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim1_brk_tim15_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim1_up_tim16_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim1_trg_com_tim17_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim1_cc_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim4_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void i2c1_ev_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void i2c1_er_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void i2c2_ev_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void i2c2_er_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void spi1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void spi2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void usart1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void usart2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void usart3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void exti15_10_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void rtc_alarm_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void cec_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim12_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim13_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim14_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void fsmc_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim5_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void spi3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void uart4_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void uart5_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim6_dac_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void tim7_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma2_channel1_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma2_channel2_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dma2_channel3_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));
extern void dam2_channel4_5_irq_handler(void) __attribute__ ((weak, alias ("int_default_handler")));

//Entry point for the application:
extern int main(void);

//Pointer to the stack top from the linker script:
extern void _vStackTop(void);

//Array used to construct the vector table at the bottom of flash.
void (* const functionVectors[])(void);

#endif /*___STARTUP_H___*/

