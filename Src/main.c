/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rohan Guraja
 * @brief          : Main program body
 ******************************************************************************
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int global_variable;

int main(void)
{
    /* Loop forever */
	for(;;)
	{
		printf("Hello World\n");
	}
}
