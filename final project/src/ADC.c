#include "LPC11xx.h"   // Device header
#include <stdio.h>
#include <string.h>
#define char  GcRcvBuf[20];//ADC���ݻ�����
				
	void delay(uint32_t ulTime)
{
	uint32_t i;
	i = 0;
	while(ulTime--)
	{
		for(i=0;i<5000;i++);
		
	}
	
}
void ADC_Init(void)
{
	LPC_SYSCON ->SYSAHBCLKCTRL|=(1<<16);
	LPC_IOCON ->R_PIO1_0 &=~0XBF;//����PIO1_0Ϊģ������ģʽ
	LPC_IOCON ->R_PIO1_0 |=0X02;//P1.0ģ������ͨ��1
	LPC_SYSCON->PDRUNCFG &=~(0X01<<4);//ADCģ���ϵ�
	LPC_SYSCON ->SYSAHBCLKCTRL |=(0X01<<13);//ʹ��ADCģ��ʱ��
	LPC_ADC ->CR = (0X02<<0)|//SEL=2��ѡ��ADC��ADC1
	               ((SystemCoreClock /1000000-1)<<8)|//ת��ʱ��1M
								 (0<<16)|//�������ת������
								 (0<<17)|//ʹ��1clocksת��
								 (0<<24)|//ADCת��ֹͣ
								 (0<<27);//ֱ������ADCת������λ��Ч

}
