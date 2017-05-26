#include "LPC11xx.h"                    // Device header
void delay(void)
{
	uint16_t i = 4000;
  while(i--);
}
int main()
{
	LPC_GPIO2->DIR = 0xFFF;
	while(1)
	{
	LPC_GPIO2->DATA &=~(0XFFF);
		LPC_GPIO2->DATA |=(0X99);
		LPC_GPIO2->DATA &=~(1<<11);
		
		delay();
		LPC_GPIO2->DATA= 0xFFF;
	}
	
	
	
}