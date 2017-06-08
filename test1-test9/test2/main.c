#include "LPC11xx.h"   // Device header
void delay(void)
{
int i,j;
	for(i=0;i<5000;i++)
		for(j=0;j<200;j++)
	;
}
int main(void)
{
// LPC_SYSCON->SYSAHBCLKCTRL|=(1<<6);//时钟在第六位
//	LPC_IOCON->PIO2_4 &=0XF8;//配置io为gpio
LPC_GPIO2->DIR |=(1<<4);//设置输入输出
while(1)//设置引脚高低电平，默认低电平有效
{
  LPC_GPIO2->DATA &=~(1<<4);
	delay();
	LPC_GPIO2->DATA |=(1<<4);
	delay();
}
}