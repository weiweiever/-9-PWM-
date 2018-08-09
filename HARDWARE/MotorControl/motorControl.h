#ifndef _MOTORCONTROL_H
#define _MOTORCONTROL_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ�� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/6/16
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

#define motor1 1
#define motor2 2
#define motor3 3

typedef enum{	 //С��������
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
