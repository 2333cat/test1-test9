 #include "LPC11xx.h"                    // Device header
   void KEY_Init ()
	{
	LPC_GPIO2->DIR|=0xFFF;//��P2_0~P2_7����Ϊ���
	LPC_GPIO2->DATA|=(1<<8);//��P2_8~p2_11����Ϊ�ߵ�ƽ
	LPC_GPIO2->DATA|=(1<<9);
	LPC_GPIO2->DATA|=(1<<10);
	LPC_GPIO2->DATA|=(1<<11);
	LPC_GPIO3->DIR&=~(0xFF);//�����ư�����p3_0~p3_4������Ϊ����
	
	LPC_GPIO3->IE|=(1<<0);
	LPC_GPIO3->IE|=(1<<1);
	LPC_GPIO3->IE|=(1<<2);
	LPC_GPIO3->IE|=(1<<3);
	LPC_GPIO3->IE|=(1<<4);//����p3_0~p3_4�ϲ����ж�
	
	LPC_GPIO3->IS&=~(1<<0);
	LPC_GPIO3->IS&=~(1<<1);
	LPC_GPIO3->IS&=~(1<<2);
	LPC_GPIO3->IS&=~(1<<3);
	LPC_GPIO3->IS&=~(1<<4);//����p3_0~p3_4�ϵ��жϱ��ش���
	
	LPC_GPIO3->IEV&=~(1<<0);
	LPC_GPIO3->IEV&=~(1<<1);
	LPC_GPIO3->IEV&=~(1<<2);
	LPC_GPIO3->IEV&=~(1<<3);
	LPC_GPIO3->IEV&=~(1<<4);//����p3_0~p3_4�ϵ��ж��½�����Ч
	NVIC_EnableIRQ(EINT3_IRQn);
}