#include "Timer.h"
#include "Ultrasound.h"
#include "delay.h"
#include "usart.h"

u16 last_cnt1=0,last_cnt2=0,last_cnt3=0;
u16 cnt1=0,cnt2=0,cnt3=0; 
s32 V1,V2,V3;


//��ʱ�ж�
void TIM7_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///ʹ��TIM7ʱ��
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//��ʼ��TIM3
	
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //����ʱ��7�����ж�
	TIM_Cmd(TIM7,ENABLE); //ʹ�ܶ�ʱ��7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn; //��ʱ��7�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

//��ʱ��7�жϷ�����
void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //����ж�
	{
		cnt1=TIM3->CNT;		//��������
		cnt2=TIM4->CNT;
		cnt3=TIM5->CNT;
		
		if(cnt1-last_cnt1>1000)
			V1=cnt1-last_cnt1-10000;
		else if(last_cnt1-cnt1>1000)
				V1=1000-last_cnt1+cnt1;
			else
				V1=cnt1-last_cnt1;
					
		if(cnt2-last_cnt2>1000)
			V1=cnt2-last_cnt2-10000;
		else if(last_cnt2-cnt2>1000)
				V2=1000-last_cnt2+cnt2;
			else
				V2=cnt2-last_cnt2;
			
		if(cnt3-last_cnt3>1000)
			V3=cnt3-last_cnt3-10000;
		else if(last_cnt3-cnt3>1000)
				V3=1000-last_cnt3+cnt3;
			else
				V3=cnt3-last_cnt3;
		
		last_cnt1=cnt1;
		last_cnt2=cnt2;
		last_cnt3=cnt3;
					
		Trig1=1;	//������
		Trig2=1;
		delay_us(11);
		Trig1=0;
		Trig2=0;
			
		/*	
		TIM_SetCompare1(TIM14,PIDcalc(PID1,V1));	//�޸ıȽ�ֵ���޸�ռ�ձ�
		TIM_SetCompare1(TIM13,PIDcalc(PID2,V2));	//�޸ıȽ�ֵ���޸�ռ�ձ�
		TIM_SetCompare1(TIM12,PIDcalc(PID3,V3));
			*/
	}
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);  //����жϱ�־λ
}
