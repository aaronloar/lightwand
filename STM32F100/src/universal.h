/*
 ********************************************************************************
 ** File:  universal.h
 **
 ** Description:
 ** Header file that contains universal information for the project.
 ********************************************************************************
 ** DJB 11/213/13 Created
 ********************************************************************************
 */


#ifndef ___UNIVERSAL_H___
#define ___UNIVERSAL_H___

//------------------------------------------------------------------------------
//Defines
//Bit masks:

#define BIT31                               0x80000000
#define BIT30                               0x40000000
#define BIT29                               0x20000000
#define BIT28                               0x10000000
#define BIT27                               0x08000000
#define BIT26                               0x04000000
#define BIT25                               0x02000000
#define BIT24                               0x01000000
#define BIT23                               0x00800000
#define BIT22                               0x00400000
#define BIT21                               0x00200000
#define BIT20                               0x00100000
#define BIT19                               0x00080000
#define BIT18                               0x00040000
#define BIT17                               0x00020000
#define BIT16                               0x00010000
#define BIT15                               0x00008000
#define BIT14                               0x00004000
#define BIT13                               0x00002000
#define BIT12                               0x00001000
#define BIT11                               0x00000800
#define BIT10                               0x00000400
#define BIT9                                0x00000200
#define BIT8                                0x00000100
#define BIT7                                0x00000080
#define BIT6                                0x00000040
#define BIT5                                0x00000020
#define BIT4                                0x00000010
#define BIT3                                0x00000008
#define BIT2                                0x00000004
#define BIT1                                0x00000002
#define BIT0                                0x00000001

//Base addresses:
#define NVIC_BASE                           0xE000E100

#define CRC_BASE                            0x40023000
#define FLASH_MEMORY_INTERFACE_BASE         0x40022000
#define RESET_AND_CLOCK_CONTROL_RCC_BASE    0x40021000
#define DMA1_BASE                           0x40020000
#define TIM17_TIMER_BASE                    0x40014800
#define TIM16_TIMER_BASE                    0x40014400
#define TIM15_TIMER_BASE                    0x40014000
#define USART1_BASE                         0x40013800
#define SPI1_BASE                           0x40013000
#define TIM1_TIMER_BASE                     0x40012C00
#define ADC1_BASE                           0x40012400
#define GPIO_PORT_E_BASE                    0x40011800
#define GPIO_PORT_D_BASE                    0x40011400
#define GPIO_PORT_C_BASE                    0x40011000
#define GPIO_PORT_B_BASE                    0x40010C00
#define GPIO_PORT_A_BASE                    0x40010800
#define EXTI_BASE                           0x40010400
#define AFIO_BASE                           0x40010000
#define CEC_BASE                            0x40007800
#define DAC_BASE                            0x40007400
#define POWER_CONTROL_BASE                  0x40007000
#define BACKUP_REGISTERS_BASE               0x40006C00
#define I2C2_BASE                           0x40005800
#define I2C1_BASE                           0x40005400
#define USART3_BASE                         0x40004800
#define USART2_BASE                         0x40004400
#define SPI2_BASE                           0x40003800
#define INDEPENDANT_WATCHDOG_BASE           0x40003000
#define WINDOW_WATCHDOG_BASE                0x40002C00
#define RTC_BASE                            0x40002800
#define TIM7_TIMER_BASE                     0x40001400
#define TIM6_TIMER_BASE                     0x40001000
#define TIM4_TIMER_BASE                     0x40000800
#define TIM3_TIMER_BASE                     0x40000400
#define TIM2_TIMER_BASE                     0x40000000

#define NVIC_ISER1                          (*((volatile unsigned int*)(NVIC_BASE + 0x04)))

#define RCC_CR                              (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x00)))
#define RCC_CFGR                            (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x04)))
#define RCC_AHBENR                          (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x14)))
#define RCC_APB2ENR                         (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x18)))
#define RCC_APB1ENR                         (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x1C)))
#define RCC_CFGR2                           (*((volatile unsigned int*)(RESET_AND_CLOCK_CONTROL_RCC_BASE + 0x2C)))
#define PLL_RDY_BIT                         (RCC_CR & BIT25)
#define HSE_RDY_BIT                         (RCC_CR & BIT17)

#define GPIOA_CRL                           (*((volatile unsigned int*)(GPIO_PORT_A_BASE + 0x00)))
#define GPIOA_CRH                           (*((volatile unsigned int*)(GPIO_PORT_A_BASE + 0x04)))
#define GPIOA_BSRR                          (*((volatile unsigned int*)(GPIO_PORT_A_BASE + 0x10)))
#define SET_PA0                             (GPIOA_BSRR = 0x00000001)
#define CLEAR_PA0                           (GPIOA_BSRR = 0x00010000)
#define SET_PA1                             (GPIOA_BSRR = 0x00000002)
#define CLEAR_PA1                           (GPIOA_BSRR = 0x00020000)
#define SET_PA2                             (GPIOA_BSRR = 0x00000004)
#define CLEAR_PA2                           (GPIOA_BSRR = 0x00040000)
#define SET_PA3                             (GPIOA_BSRR = 0x00000008)
#define CLEAR_PA3                           (GPIOA_BSRR = 0x00080000)

#define GPIOB_CRH                           (*((volatile unsigned int*)(GPIO_PORT_B_BASE + 0x04)))
#define GPIOB_BSRR                          (*((volatile unsigned int*)(GPIO_PORT_B_BASE + 0x10)))

#define SET_PB9                             (GPIOB_BSRR = 0x00000200)
#define CLEAR_PB9                           (GPIOB_BSRR = 0x02000000)

#define GPIOC_CRH                           (*((volatile unsigned int*)(GPIO_PORT_C_BASE + 0x04)))
#define GPIOC_IDR                           (*((volatile unsigned int*)(GPIO_PORT_C_BASE + 0x08)))
#define GPIOC_ODR                           (*((volatile unsigned int*)(GPIO_PORT_C_BASE + 0x0C)))
#define GPIOC_BSRR                          (*((volatile unsigned int*)(GPIO_PORT_C_BASE + 0x10)))

#define SET_PC8                             (GPIOC_BSRR = 0x00000100)
#define CLEAR_PC8                           (GPIOC_BSRR = 0x01000000)
#define SET_PC9                             (GPIOC_BSRR = 0x00000200)
#define CLEAR_PC9                           (GPIOC_BSRR = 0x02000000)

//#define WRITE_PORTB_LOWBYTE(x)              (GPIOB_ODR = (unsigned int)x)

#define TIM6_CR1                            (*((volatile unsigned int*)(TIM6_TIMER_BASE + 0x00)))
#define TIM6_DIER                           (*((volatile unsigned int*)(TIM6_TIMER_BASE + 0x0C)))
#define TIM6_SR                             (*((volatile unsigned int*)(TIM6_TIMER_BASE + 0x10)))
#define TIM6_PSC                            (*((volatile unsigned int*)(TIM6_TIMER_BASE + 0x28)))
#define TIM6_ARR                            (*((volatile unsigned int*)(TIM6_TIMER_BASE + 0x2C)))

#define TIM6_CLEAR_UIF_BIT                       (TIM6_SR &= ~BIT0)

#define TIM7_CR1                            (*((volatile unsigned int*)(TIM7_TIMER_BASE + 0x00)))
#define TIM7_DIER                           (*((volatile unsigned int*)(TIM7_TIMER_BASE + 0x0C)))
#define TIM7_SR                             (*((volatile unsigned int*)(TIM7_TIMER_BASE + 0x10)))
#define TIM7_PSC                            (*((volatile unsigned int*)(TIM7_TIMER_BASE + 0x28)))
#define TIM7_ARR                            (*((volatile unsigned int*)(TIM7_TIMER_BASE + 0x2C)))

#define TIM7_CLEAR_UIF_BIT                       (TIM7_SR &= ~BIT0)


#define NUM_LED         3
#define STEPS           316


//------------------------------------------------------------------------------
//Enumerations
//None

//------------------------------------------------------------------------------
//Structures
//None

//------------------------------------------------------------------------------
//Prototypes
//None

#endif /*___UNIVERSAL_H___*/
