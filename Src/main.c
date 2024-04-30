/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rohan Guraja
 * @brief          : Program to print values onto an external monitor using ITM
 ******************************************************************************
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//RCC register address to set the HSI as system clock
#define RCC_BASE_ADDR			(0x40021000UL)
#define RCC_CR_OFFSET_ADDR		(0x00UL)
#define RCC_CR_ADDR				(RCC_BASE_ADDR+RCC_CR_OFFSET_ADDR)

#define RCC_CFGR_OFFSET_ADDR 		(0x04UL)
#define RCC_CFGR_ADDR				(RCC_BASE_ADDR+RCC_CFGR_OFFSET_ADDR)

int main(void)
{
	//Code to set system clock to 8Mhz.
	//We need to enable serial wide viewer and set the Core clock to 8 Mhz for the ITM console to work.
	//This is just a precausionary part and totally can be skipped because most times HSI is configured as system clock

	uint32_t *pRCC_CR =(uint32_t *)RCC_CR_ADDR;
	uint32_t *pRCC_CFGR =(uint32_t *) RCC_CFGR_ADDR;

	//set RCC_CR  Bit0 to 1 to select HSI as system clock
	*pRCC_CR |= 1<<0;

	//wait till clock is ready check RCC_CR Bit1
	while( (*pRCC_CR & (1<<1)) == 0 )
	{
		//do nothing
	}

	//set RCC_CFGR Bit 1:0 to 00
	*pRCC_CFGR |= (0<<1);
	*pRCC_CFGR |= (0<<0);

	//check RCC_CFGR Bit 3:2 are 00 to check if HSI is used as system clock
	while(((*pRCC_CFGR&(1<<3))!=0) && ((*pRCC_CFGR&(1<<2))!=0))
	{

	}

    /* Loop forever */
	while(1)
	{
		printf("Hello World\n");
	}
}
