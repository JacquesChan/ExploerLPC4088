//#include "LPC407x_8x_177x_8x.h"
#include "delay.h"
#include "chip.h"

/* System oscillator rate and RTC oscillator rate */
const uint32_t OscRateIn = 12000000;
const uint32_t RTCOscRateIn = 32768;

int main(void)
{
//Initialize GPIO1
	 Chip_GPIO_Init(LPC_GPIO);
   Chip_GPIO_SetPinState(LPC_GPIO, 2, 26, true);	
	 delay_ms(10);
	 Chip_GPIO_SetPinToggle(LPC_GPIO, 2, 26);
	 delay_ms(10);
}