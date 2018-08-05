#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "motorControl.h"
#include "Ultrasound.h"
#include "stm32f4xx.h"

//ALIENTEK ̽����STM32F407������ ʵ��9
//PWM���ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
u16 cnt4,cnt3,cnt5;
extern u8  TIM9CH1_CAPTURE_STA;	//���벶��״̬		    				
extern u32	TIM9CH1_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)
extern u8  TIM10CH1_CAPTURE_STA;		    				
extern u32	TIM10CH1_CAPTURE_VAL;


long long temp;

		
int main(void)
{ 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM14_PWM_Init(500-1,84-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz. 
	TIM13_PWM_Init(500-1,84-1);	
	TIM12_PWM_Init(500-1,84-1);
	TIM9_Ultrasound_cap_Init(0XFFFFFFFF,84-1); //��1Mhz��Ƶ�ʼ���
	TIM10_Ultrasound_cap_Init(0XFFFFFFFF,84-1);
	TIM5_encoder_Init(); 
	TIM4_encoder_Init();
	TIM3_encoder_Init();
	TIM7_Int_Init(5000,84-1);	//5ms�ж�
	Ultrasound_trig_Init();
	
	TIM_SetCompare1(TIM14,250);	//�޸ıȽ�ֵ���޸�ռ�ձ�
	TIM_SetCompare1(TIM13,250);	//�޸ıȽ�ֵ���޸�ռ�ձ�
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
		
		if(TIM9CH1_CAPTURE_STA&0X80)        //�ɹ�������һ�θߵ�ƽ
			{
				temp=TIM9CH1_CAPTURE_STA&0X3F; 
				temp*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
				temp+=TIM9CH1_CAPTURE_VAL;		   //�õ��ܵĸߵ�ƽʱ��
				printf("1HIGH:%lld us",temp); //��ӡ�ܵĸߵ�ƽʱ��
				TIM9CH1_CAPTURE_STA=0;			     //������һ�β���

			}
		if(TIM10CH1_CAPTURE_STA&0X80)        //�ɹ�������һ�θߵ�ƽ
			{
				temp=TIM10CH1_CAPTURE_STA&0X3F; 
				temp*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
				temp+=TIM10CH1_CAPTURE_VAL;		   //�õ��ܵĸߵ�ƽʱ��
				printf("2HIGH:%lld us\r\n",temp); //��ӡ�ܵĸߵ�ƽʱ��
				TIM10CH1_CAPTURE_STA=0;			     //������һ�β���

			}
		
		cnt3 = TIM3 -> CNT;
		cnt4 = TIM4 -> CNT;
		cnt5 = TIM5 -> CNT;
		printf("%5d  %5d  %5d\r\n",cnt3,cnt4,cnt5);
	}
}


