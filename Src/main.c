/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include<stm32f407xx_gpio_driver.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay()
{
	for(uint32_t i=0;i<500000;i++);
}

int main(void)

{
	GPIO_Handle_t GPIOLed,GPIOBtn;
		GPIOLed.pGPIOx = GPIOD;
		GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GIPO_PIN_NO_12 ;
		GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
		GPIOLed.GPIO_PinConfig.GPIO_PinOpType = OUTPUT_PUPL ;
		GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = NO_PUPD ;
		GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = VHG_SPD ;

		GPIO_ClockControl(GPIOD , ENABLE);
		GPIO_Init(&GPIOLed);

		GPIOBtn.pGPIOx = GPIOA;
		GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GIPO_PIN_NO_0 ;
		GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
		GPIOBtn.GPIO_PinConfig.GPIO_PinPuPdControl = NO_PUPD ;
		GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = VHG_SPD ;
		GPIO_ClockControl(GPIOA , ENABLE);
	    GPIO_Init(&GPIOBtn);
		while(1)
		{
			if(GPIO_ReadFromInputPin(GPIOA,GIPO_PIN_NO_0))
			{
				delay();
				GPIO_TogglePin(GPIOD, GIPO_PIN_NO_12);
			}


		}
}