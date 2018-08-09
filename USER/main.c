#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "motorControl.h"
#include "Ultrasound.h"
#include "Timer.h"
#include "stm32f4xx.h"

extern long long dis1,dis2;	//记录上一次测到的距离
		
int main(void){ 
	
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
	motor_Direction_Pin_Init();
	//PID_Init(0.08,0.1,0.1);
	
	Trig1=0;
	Trig2=0;
	
	set_Car_Direction(ahead);
	
	while(1){
		if(dis1==0||dis2==0) continue;
		if(dis1<5000 && dis2<5000){
			delay_ms(5);
			if(dis1<7000 && dis2<7000){
				car_Stop();
				delay_ms(400);
				set_Car_Direction(right);
				while(dis1<7000)
					delay_ms(3);
				delay_ms(100);
				car_Stop();
				delay_ms(400);
			}
		}
		
		if(dis1<5000 && dis2>5000){
			delay_ms(5);
			if(dis1<7000 && dis2>3000){
				car_Stop();
				delay_ms(400);
				set_Car_Direction(right);
				while(dis1<7000)
					delay_ms(3);
				delay_ms(100);
				car_Stop();
				delay_ms(400);
			}
		}
		
		if(dis1>5000 && dis2<5000){
			delay_ms(5);
			if(dis1>3000 && dis2<7000){
				car_Stop();
				delay_ms(400);
				set_Car_Direction(left);
				while(dis2<7000)
					delay_ms(3);
				delay_ms(100);
				car_Stop();
				delay_ms(400);
			}
		}
		
		if(dis1>5000 && dis2>5000){
			delay_ms(5);
			if(dis1>3000 && dis2>3000){
				car_Stop();
				delay_ms(400);
				set_Car_Direction(ahead);
				
			}
		}

	}
}


