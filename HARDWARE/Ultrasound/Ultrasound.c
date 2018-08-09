#include "Ultrasound.h"
#include "usart.h"

void TIM9_Ultrasound_cap_Init(u32 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_ICInitTypeDef  TIM9_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);  	//TIM9ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//ʹ��PORTEʱ��	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOE,&GPIO_InitStructure); //��ʼ��PE5

	GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9); //PE5����λ��ʱ��9
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM9,&TIM_TimeBaseStructure);
	

	//��ʼ��TIM5���벶�����
	TIM9_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  TIM9_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  TIM9_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  TIM9_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  TIM9_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  TIM_ICInit(TIM9, &TIM9_ICInitStructure);
	
	TIM_ITConfig(TIM9,TIM_IT_Update|TIM_IT_CC1,ENABLE);//��������ж� ,����CC1IE�����ж�	
  TIM_Cmd(TIM9,ENABLE ); 	//ʹ�ܶ�ʱ��9

 
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
}


void TIM10_Ultrasound_cap_Init(u32 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_ICInitTypeDef  TIM10_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);  	//TIM10ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//ʹ��PORTBʱ��	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //GPIOB
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(GPIOB,&GPIO_InitStructure); //��ʼ��PE5

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM10); //PB8����λ��ʱ��10
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM10,&TIM_TimeBaseStructure);
	

	//��ʼ��TIM5���벶�����
	TIM10_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  TIM10_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  TIM10_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  TIM10_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  TIM10_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  TIM_ICInit(TIM10, &TIM10_ICInitStructure);
	
	TIM_ITConfig(TIM10,TIM_IT_Update|TIM_IT_CC1,ENABLE);//��������ж� ,����CC1IE�����ж�	
  TIM_Cmd(TIM10,ENABLE ); 	//ʹ�ܶ�ʱ��10

 
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
}

//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)
u8  TIM9CH1_CAPTURE_STA=0;	//���벶��״̬		    				
u32	TIM9CH1_CAPTURE_VAL=0;	//���벶��ֵ(TIM2/TIM5��32λ)
u8  TIM10CH1_CAPTURE_STA=0;		    				
u32	TIM10CH1_CAPTURE_VAL=0;	

long long dis1=10000,dis2=10000;		//��¼��һ�β⵽�ľ���

//��ʱ��9�жϷ������	 
void TIM1_BRK_TIM9_IRQHandler(void)
{ 	
		if((TIM9CH1_CAPTURE_STA&0X80)==0)//��δ�ɹ�����	
		{
			if(TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET)//���
			{	     
				if(TIM9CH1_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
				{
					if((TIM9CH1_CAPTURE_STA&0X3F)==0X1F)//�ߵ�ƽ̫����		
					{
						TIM9CH1_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
						TIM9CH1_CAPTURE_VAL=0XFFFFFFFF;
						dis1=0X1F; 
						dis1*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
						dis1+=TIM9CH1_CAPTURE_VAL;
						TIM9CH1_CAPTURE_STA=0;
						TIM9CH1_CAPTURE_VAL=0;
					}else TIM9CH1_CAPTURE_STA++;
				}	 
			}
			if(TIM_GetITStatus(TIM9, TIM_IT_CC1) != RESET)//����1���������¼�
			{	
				if(TIM9CH1_CAPTURE_STA&0X40)		//����һ���½��� 		
				{
					TIM9CH1_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
					TIM9CH1_CAPTURE_VAL=TIM_GetCapture1(TIM9);//��ȡ��ǰ�Ĳ���ֵ.
					TIM_OC1PolarityConfig(TIM9,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
					dis1=TIM9CH1_CAPTURE_STA&0X3F; 
					dis1*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
					dis1+=TIM9CH1_CAPTURE_VAL;
					TIM9CH1_CAPTURE_STA=0;
					TIM9CH1_CAPTURE_VAL=0;
				}else  								//��δ��ʼ,��һ�β���������
				{
					TIM9CH1_CAPTURE_STA=0;			//���
					TIM9CH1_CAPTURE_VAL=0;
					TIM9CH1_CAPTURE_STA|=0X40;		//��ǲ�����������
					TIM_Cmd(TIM9,DISABLE ); 	//�رն�ʱ��9
					TIM_SetCounter(TIM9,0);
					TIM_OC1PolarityConfig(TIM9,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
					TIM_Cmd(TIM9,ENABLE ); 	//ʹ�ܶ�ʱ��9
				}		    
			}			     	    					   
		}
		TIM_ClearITPendingBit(TIM9, TIM_IT_CC1|TIM_IT_Update); //����жϱ�־λ
}

//��ʱ��10�жϷ������	 
void TIM1_UP_TIM10_IRQHandler(void)
{ 		    
		if((TIM10CH1_CAPTURE_STA&0X80)==0)//��δ�ɹ�����	
		{
			if(TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)//���
			{	     
				if(TIM10CH1_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
				{
					if((TIM10CH1_CAPTURE_STA&0X3F)==0X1F)//�ߵ�ƽ̫����
					{
						TIM10CH1_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
						TIM10CH1_CAPTURE_VAL=0XFFFFFFFF;
						dis2=0X1F; 
						dis2*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
						dis2+=TIM10CH1_CAPTURE_VAL;
						TIM10CH1_CAPTURE_STA=0;
						TIM10CH1_CAPTURE_VAL=0;
					}else TIM10CH1_CAPTURE_STA++;
				}	 
			}
			if(TIM_GetITStatus(TIM10, TIM_IT_CC1) != RESET)//����1���������¼�
			{	
				if(TIM10CH1_CAPTURE_STA&0X40)		//����һ���½��� 		
				{	  			
					TIM10CH1_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
					TIM10CH1_CAPTURE_VAL=TIM_GetCapture1(TIM10);//��ȡ��ǰ�Ĳ���ֵ.
					TIM_OC1PolarityConfig(TIM10,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
					dis2=TIM10CH1_CAPTURE_STA&0X3F; 
					dis2*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
					dis2+=TIM10CH1_CAPTURE_VAL;
					TIM10CH1_CAPTURE_STA=0;
					TIM10CH1_CAPTURE_VAL=0;
				}else  								//��δ��ʼ,��һ�β���������
				{
					TIM10CH1_CAPTURE_STA=0;			//���
					TIM10CH1_CAPTURE_VAL=0;
					TIM10CH1_CAPTURE_STA|=0X40;		//��ǲ�����������
					TIM_Cmd(TIM10,DISABLE ); 	//�رն�ʱ��10
					TIM_SetCounter(TIM10,0);
					TIM_OC1PolarityConfig(TIM10,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
					TIM_Cmd(TIM10,ENABLE ); 	//ʹ�ܶ�ʱ��10
				}		    
			}			     	    					   
		}
		TIM_ClearITPendingBit(TIM10, TIM_IT_CC1|TIM_IT_Update); //����жϱ�־λ
}

void Ultrasound_trig_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//ʹ��PORTEʱ��	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOE,&GPIO_InitStructure); //��ʼ��PE5

	GPIO_ResetBits(GPIOE,GPIO_Pin_2 | GPIO_Pin_3);
}
