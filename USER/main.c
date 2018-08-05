#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "motorControl.h"
#include "Ultrasound.h"
#include "stm32f4xx.h"

//ALIENTEK 探索者STM32F407开发板 实验9
//PWM输出实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
u16 cnt4,cnt3,cnt5;
extern u8  TIM9CH1_CAPTURE_STA;	//输入捕获状态		    				
extern u32	TIM9CH1_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)
extern u8  TIM10CH1_CAPTURE_STA;		    				
extern u32	TIM10CH1_CAPTURE_VAL;


long long temp;

		
int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);//初始化串口波特率为115200
 	TIM14_PWM_Init(500-1,84-1);	//84M/84=1Mhz的计数频率,重装载值500，所以PWM频率为 1M/500=2Khz. 
	TIM13_PWM_Init(500-1,84-1);	
	TIM12_PWM_Init(500-1,84-1);
	TIM9_Ultrasound_cap_Init(0XFFFFFFFF,84-1); //以1Mhz的频率计数
	TIM10_Ultrasound_cap_Init(0XFFFFFFFF,84-1);
	TIM5_encoder_Init(); 
	TIM4_encoder_Init();
	TIM3_encoder_Init();
	TIM7_Int_Init(5000,84-1);	//5ms中断
	Ultrasound_trig_Init();
	
	TIM_SetCompare1(TIM14,250);	//修改比较值，修改占空比
	TIM_SetCompare1(TIM13,250);	//修改比较值，修改占空比
	TIM_SetCompare1(TIM12,250);

   while(1) 
	{
		Trig1=0;
		Trig2=0;
 		delay_ms(10);	 
		Trig1=1;
		Trig2=1;
		delay_us(15);
		Trig1=0;
		Trig2=0;
		
		if(TIM9CH1_CAPTURE_STA&0X80)        //成功捕获到了一次高电平
			{
				temp=TIM9CH1_CAPTURE_STA&0X3F; 
				temp*=0XFFFFFFFF;		 		         //溢出时间总和
				temp+=TIM9CH1_CAPTURE_VAL;		   //得到总的高电平时间
				printf("1HIGH:%lld us",temp); //打印总的高点平时间
				TIM9CH1_CAPTURE_STA=0;			     //开启下一次捕获

			}
		if(TIM10CH1_CAPTURE_STA&0X80)        //成功捕获到了一次高电平
			{
				temp=TIM10CH1_CAPTURE_STA&0X3F; 
				temp*=0XFFFFFFFF;		 		         //溢出时间总和
				temp+=TIM10CH1_CAPTURE_VAL;		   //得到总的高电平时间
				printf("2HIGH:%lld us\r\n",temp); //打印总的高点平时间
				TIM10CH1_CAPTURE_STA=0;			     //开启下一次捕获

			}
		
		cnt3 = TIM3 -> CNT;
		cnt4 = TIM4 -> CNT;
		cnt5 = TIM5 -> CNT;
		printf("%5d  %5d  %5d\r\n",cnt3,cnt4,cnt5);
	}
}


