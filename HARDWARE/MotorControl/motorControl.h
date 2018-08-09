#ifndef _MOTORCONTROL_H
#define _MOTORCONTROL_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//定时器 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/6/16
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define motor1 1
#define motor2 2
#define motor3 3

typedef enum{	 //小车方向定义
	ahead = 1,
	back  = 2,
	left  = 3,
	right = 4
}carDirectionType;

void TIM14_PWM_Init(u32 arr,u32 psc);
void TIM13_PWM_Init(u32 arr,u32 psc);
void TIM12_PWM_Init(u32 arr,u32 psc);

void TIM4_encoder_Init(void);
void TIM3_encoder_Init(void);
void TIM5_encoder_Init(void);



void motor_Direction_Pin_Init(void);
void PID_Init(float Kp,float Ki,float Kd);
void set_motor_speed(int motor,int speed);
void car_Stop(void);
void set_Car_Direction(carDirectionType drct);
#endif
