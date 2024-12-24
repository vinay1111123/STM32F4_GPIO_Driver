/*
 * stm32f4xx.h
 *
 *  Created on: Dec 20, 2024
 *      Author: vinay
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include<stdint.h>


/*
 * Some generic macros
 */
#define ENABLE                   1
#define DISABLE                  0
#define SET                      ENABLE
#define RESET                    DISABLE
#define GPIO_PIN_SET             ENABLE
#define GPIO_PIN_RESET           DISABLE

#define __vo                     volatile

/* Base addresses of different memories */

#define SRAM_BASE_ADDR           0x20000000U
#define SRAM1_BASE_ADDR          SRAM_BASE_ADDR
#define END_OF_SRAM1             (SRAM1_BASE_ADDR + (112*1024))U
#define SRAM2_BASE_ADDR          END_OF_SRAM1
#define FLASH_MEM_BASE_ADDR      0x08000000U
#define ROM_BASE_ADDR            0x1FFF0000U


/* Base addresses of different buses */

#define APB1_BASE_ADDR          0x40000000U
#define APB2_BASE_ADDR          0x40010000U
#define AHB1_BASE_ADDR          0x40020000U
#define AHB2_BASE_ADDR          0x50000000U
#define AHB3_BASE_ADDR          0xA0000000U

/*
 * Base Addresses of all peripherals hanged on AHB1 bus
 */
#define GPIOA_BASE_ADDR        (AHB1_BASE_ADDR+(0X0000))
#define GPIOB_BASE_ADDR        (AHB1_BASE_ADDR+(0X0400))
#define GPIOC_BASE_ADDR        (AHB1_BASE_ADDR+(0X0800))
#define GPIOD_BASE_ADDR        (AHB1_BASE_ADDR+(0X0C00))
#define GPIOE_BASE_ADDR        (AHB1_BASE_ADDR+(0X1000))
#define GPIOF_BASE_ADDR        (AHB1_BASE_ADDR+(0X1400))
#define GPIOG_BASE_ADDR        (AHB1_BASE_ADDR+(0X1800))
#define GPIOH_BASE_ADDR        (AHB1_BASE_ADDR+(0X1C00))
#define GPIOI_BASE_ADDR        (AHB1_BASE_ADDR+(0X2000))


#define RCC_BASE_ADDR           0x40023800U

/*
 * GPIO Register structure definition
 */

typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFRL;
	__vo uint32_t AFRH;

}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCGFR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	__vo uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	__vo uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t RCC_DCKCFGR;
}Rcc_RegDef_t;



/*
 * create pointers for every GPIO
 */

#define  GPIOA              (GPIO_RegDef_t*)GPIOA_BASE_ADDR
#define  GPIOB              (GPIO_RegDef_t*)GPIOB_BASE_ADDR
#define  GPIOC              (GPIO_RegDef_t*)GPIOC_BASE_ADDR
#define  GPIOD              (GPIO_RegDef_t*)GPIOD_BASE_ADDR
#define  GPIOE              (GPIO_RegDef_t*)GPIOE_BASE_ADDR
#define  GPIOF              (GPIO_RegDef_t*)GPIOF_BASE_ADDR
#define  GPIOG              (GPIO_RegDef_t*)GPIOG_BASE_ADDR
#define  GPIOH              (GPIO_RegDef_t*)GPIOH_BASE_ADDR
#define  GPIOI              (GPIO_RegDef_t*)GPIOI_BASE_ADDR


#define RCC                 ((Rcc_RegDef_t*)(RCC_BASE_ADDR))

/*
 * Clock enable macros for GPIO ports
 */

#define GPIOA_CLK_EN()  (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN()  (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN()  (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN()  (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN()  (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN()  (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN()  (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN()  (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_CLK_EN()  (RCC->AHB1ENR |= (1 << 8))

/*
 * Clock Disable macros for GPIO Ports
 */
#define GPIOA_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_CLK_DI()  (RCC->AHB1ENR &= ~(1 << 8))


/*
 * GPIO Reset
 */

#define GPIOA_RST()          (RCC->AHB1RSTR |= ~(1<<0))
#define GPIOB_RST()          (RCC->AHB1RSTR |= ~(1<<1))
#define GPIOC_RST()          (RCC->AHB1RSTR |= ~(1<<2))
#define GPIOD_RST()          (RCC->AHB1RSTR |= ~(1<<3))
#define GPIOE_RST()          (RCC->AHB1RSTR |= ~(1<<4))
#define GPIOF_RST()          (RCC->AHB1RSTR |= ~(1<<5))
#define GPIOG_RST()          (RCC->AHB1RSTR |= ~(1<<6))
#define GPIOH_RST()          (RCC->AHB1RSTR |= ~(1<<7))
#define GPIOI_RST()          (RCC->AHB1RSTR |= ~(1<<8))

#endif /* INC_STM32F4XX_H_ */
