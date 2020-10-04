#include "delay.h"
#include "chip.h"

uint32_t fac_us = 0;
uint32_t fac_ms = 0;


void delay_init(void)
{
   /* Generic Initialization */
	 SystemCoreClockUpdate(); 
}

/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
    if(fac_us) fac_us--;
    if(fac_ms) fac_ms--;
}

void delay_us(uint32_t nus)
{   
    SysTick_Config(SystemCoreClock / 1000000);  //??1us
    fac_us = nus;
    while(fac_us != 0);  
}

void delay_ms(uint32_t nms)
{                 
    SysTick_Config(SystemCoreClock / 1000);     //??1ms
    fac_ms = nms;
    while(fac_ms != 0);             
}