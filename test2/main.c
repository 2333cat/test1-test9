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
// LPC_SYSCON->SYSAHBCLKCTRL|=(1<<6);//ʱ���ڵ���λ
//	LPC_IOCON->PIO2_4 &=0XF8;//����ioΪgpio
LPC_GPIO2->DIR |=(1<<4);//�����������
while(1)//�������Ÿߵ͵�ƽ��Ĭ�ϵ͵�ƽ��Ч
{
  LPC_GPIO2->DATA &=~(1<<4);
	delay();
	LPC_GPIO2->DATA |=(1<<4);
	delay();
}
}