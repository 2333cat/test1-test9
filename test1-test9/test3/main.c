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
	LPC_GPIO2->DATA &= ~(0xFFF);
	LPC_GPIO2->DATA |= 0xC0;
	LPC_GPIO2->DATA &= ~(1<<8);
	delay();
	
	LPC_GPIO2->DATA &= ~(0xFFF);
	LPC_GPIO2->DATA |= 0xF9;
	LPC_GPIO2->DATA &= ~(1<<9);
	delay();

	LPC_GPIO2->DATA &= ~(0xFFF);
	LPC_GPIO2->DATA |= 0xA4;
	LPC_GPIO2->DATA &= ~(1<<10);
	delay();
		
	LPC_GPIO2->DATA &= ~(0xFFF);
	LPC_GPIO2->DATA |= 0xB0;
	LPC_GPIO2->DATA &= ~(1<<11);
	delay();
		
	}
	
	
	
}