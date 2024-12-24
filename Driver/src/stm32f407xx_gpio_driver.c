/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Dec 22, 2024
 *      Author: vinay
 */


#include"stm32f407xx_gpio_driver.h"
#include<stdint.h>



/*
 * GPIO clock control
 */
void GPIO_ClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
    	if(pGPIOx == GPIOA)
    	{
            GPIOA_CLK_EN();
    	}
    	else if(pGPIOx == GPIOB)
    	{
    		GPIOB_CLK_EN();
    	}
    	else if(pGPIOx == GPIOC)
    	{
    	    GPIOC_CLK_EN();
    	}
    	else if(pGPIOx == GPIOD)
    	{
    	    GPIOD_CLK_EN();
    	}
    	else if(pGPIOx == GPIOE)
    	{
    	    GPIOE_CLK_EN();
     	}
    	else if(pGPIOx == GPIOF)
    	{
    	  	GPIOF_CLK_EN();
    	}
    	else if(pGPIOx == GPIOG)
    	{
    	   	GPIOG_CLK_EN();
    	}
    	else if(pGPIOx == GPIOH)
    	{
    	  	GPIOH_CLK_EN();
    	}
    	else if(pGPIOx == GPIOB)
    	{
    	  	GPIOB_CLK_EN();
    	}
    	else if(pGPIOx == GPIOI)
    	{
    	   GPIOI_CLK_EN();
    	}
    }
    else
    {
    	if(pGPIOx == GPIOA)
    	 {
    	     GPIOA_CLK_DI();
    	 }
    	else if(pGPIOx == GPIOB)
    	   {
    	     GPIOB_CLK_DI();
    	   }
    	else if(pGPIOx == GPIOC)
    	   {
    	     GPIOC_CLK_DI();
    	   }
       else if(pGPIOx == GPIOD)
    	   {
    	     GPIOD_CLK_DI();
    	   }
       else if(pGPIOx == GPIOE)
    	   {
    	      GPIOE_CLK_DI();
    	   }
       else if(pGPIOx == GPIOF)
    	   {
    	   	GPIOF_CLK_DI();
    	   }
       else if(pGPIOx == GPIOG)
    	   {
    	   	GPIOG_CLK_DI();
    	   }
       else if(pGPIOx == GPIOH)
    	   {
    	   	GPIOH_CLK_DI();
    	   }
       else if(pGPIOx == GPIOB)
    	   {
    	   	GPIOB_CLK_DI();
    	   }
       else if(pGPIOx == GPIOI)
    	   {
    	     GPIOI_CLK_DI();
    	   }
    }
}

/*
 * GPIO Initialization and GPIO Deinitialization
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
    //1.Configure the mode of GPIO pin
	uint32_t temp=0;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//Non interrupt mode
		temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &=~(0x3<< 2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//Clearing the ModeR register
		pGPIOHandle->pGPIOx->MODER |= temp; //Setting the MODER register
	}
	else
	{
		//Interrupt mode
	}
	temp=0;
	//2.Configure the speed

     temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
     pGPIOHandle->pGPIOx->OSPEEDR &=~(0x3<< 2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//Clearing the ModeR register
     pGPIOHandle->pGPIOx->OSPEEDR |= temp;
     temp=0;

     //3.Configure the pull up and pull down
     temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
     pGPIOHandle->pGPIOx->PUPDR &=~(0x3<< 2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);//Clearing the ModeR register
     pGPIOHandle->pGPIOx->PUPDR |= temp;
     temp=0;

     //4.Configure the output type of a register
     temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOpType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
     pGPIOHandle->pGPIOx->OTYPER &=~(0x1<< pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
     pGPIOHandle->pGPIOx->OTYPER |= temp;
     temp=0;

     //4.Configure Atlernate functionality
     if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode ==  GPIO_MODE_ALTFN)
     {

     if(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber <= 7)
     {
    	 //Alternate functionality low register
    	 temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
    	 pGPIOHandle->pGPIOx->AFRL &=~(0xF<< 4*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	 pGPIOHandle->pGPIOx->AFRL |= temp;

     }
     else
     {
    	 //Alternate Functionality high register
    	 temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*(pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)));
    	 pGPIOHandle->pGPIOx->AFRH &=~(0xF<< 4*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
    	 pGPIOHandle->pGPIOx->AFRH |= temp;
     }
     }

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	    	if(pGPIOx == GPIOA)
	    	{
	            GPIOA_RST();
	    	}
	    	else if(pGPIOx == GPIOB)
	    	{
	    		GPIOB_RST();
	    	}
	    	else if(pGPIOx == GPIOC)
	    	{
	    		GPIOC_RST();
	    	}
	    	else if(pGPIOx == GPIOD)
	    	{
	    		GPIOD_RST();	    	}
	    	else if(pGPIOx == GPIOE)
	    	{
	    		GPIOA_RST();	     	}
	    	else if(pGPIOx == GPIOF)
	    	{
	    		GPIOE_RST();
	    	}
	    	else if(pGPIOx == GPIOG)
	    	{
	    		GPIOF_RST();
	    	}
	    	else if(pGPIOx == GPIOH)
	    	{
	    		GPIOG_RST();
	    	}
	    	else if(pGPIOx == GPIOB)
	    	{
	    		GPIOH_RST();
	    	}
	    	else if(pGPIOx == GPIOI)
	    	{
	    		GPIOI_RST();
	    	}

}



/*
 * Data read and write Macros
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	  uint8_t value ;
	  value = (uint8_t)(pGPIOx->IDR >> PinNumber) & (0x00000001);
	  return value;

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t value)
{
	if(value == GPIO_PIN_SET)
	   {
		   pGPIOx->ODR |= (1<<PinNumber);
	   }
	   else
	   {
		   pGPIOx->ODR &= ~(1<<PinNumber);
	   }
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
	pGPIOx->ODR = value;
}
void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1<<PinNumber);
}


void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}
