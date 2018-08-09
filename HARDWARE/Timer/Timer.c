#include "Timer.h"
#include "Ultrasound.h"
#include "delay.h"
#include "usart.h"

u16 last_cnt1=0,last_cnt2=0,last_cnt3=0;
u16 cnt1=0,cnt2=0,cnt3=0; 
s32 V1,V2,V3;


//定时中断
void TIM7_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);  ///使能TIM7时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE); //允许定时器7更新中断
	TIM_Cmd(TIM7,ENABLE); //使能定时器7
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn; //定时器7中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

//定时器7中断服务函数
void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //溢出中断
	{
		cnt1=TIM3->CNT;		//读编码器
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
					
		Trig1=1;	//超声波
		Trig2=1;
		delay_us(11);
		Trig1=0;
		Trig2=0;
			
		/*	
		TIM_SetCompare1(TIM14,PIDcalc(PID1,V1));	//修改比较值，修改占空比
		TIM_SetCompare1(TIM13,PIDcalc(PID2,V2));	//修改比较值，修改占空比
		TIM_SetCompare1(TIM12,PIDcalc(PID3,V3));
			*/
	}
	TIM_ClearITPendingBit(TIM7,TIM_IT_Update);  //清除中断标志位
}
