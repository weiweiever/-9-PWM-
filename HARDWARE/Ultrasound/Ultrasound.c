#include "Ultrasound.h"
#include "usart.h"

void TIM9_Ultrasound_cap_Init(u32 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_ICInitTypeDef  TIM9_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);  	//TIM9时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//使能PORTE时钟	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //下拉
	GPIO_Init(GPIOE,&GPIO_InitStructure); //初始化PE5

	GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9); //PE5复用位定时器9
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM9,&TIM_TimeBaseStructure);
	

	//初始化TIM5输入捕获参数
	TIM9_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	选择输入端 IC1映射到TI1上
  TIM9_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  TIM9_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  TIM9_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  TIM9_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
  TIM_ICInit(TIM9, &TIM9_ICInitStructure);
	
	TIM_ITConfig(TIM9,TIM_IT_Update|TIM_IT_CC1,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
  TIM_Cmd(TIM9,ENABLE ); 	//使能定时器9

 
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
}


void TIM10_Ultrasound_cap_Init(u32 arr,u16 psc){
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_ICInitTypeDef  TIM10_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);  	//TIM10时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); 	//使能PORTB时钟	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //GPIOB
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //下拉
	GPIO_Init(GPIOB,&GPIO_InitStructure); //初始化PE5

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM10); //PB8复用位定时器10
	  
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM10,&TIM_TimeBaseStructure);
	

	//初始化TIM5输入捕获参数
	TIM10_ICInitStructure.TIM_Channel = TIM_Channel_1; //CC1S=01 	选择输入端 IC1映射到TI1上
  TIM10_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  TIM10_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  TIM10_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  TIM10_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
  TIM_ICInit(TIM10, &TIM10_ICInitStructure);
	
	TIM_ITConfig(TIM10,TIM_IT_Update|TIM_IT_CC1,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
  TIM_Cmd(TIM10,ENABLE ); 	//使能定时器10

 
  NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
}

//捕获状态
//[7]:0,没有成功的捕获;1,成功捕获到一次.
//[6]:0,还没捕获到低电平;1,已经捕获到低电平了.
//[5:0]:捕获低电平后溢出的次数(对于32位定时器来说,1us计数器加1,溢出时间:4294秒)
u8  TIM9CH1_CAPTURE_STA=0;	//输入捕获状态		    				
u32	TIM9CH1_CAPTURE_VAL=0;	//输入捕获值(TIM2/TIM5是32位)
u8  TIM10CH1_CAPTURE_STA=0;		    				
u32	TIM10CH1_CAPTURE_VAL=0;	

long long dis1=10000,dis2=10000;		//记录上一次测到的距离

//定时器9中断服务程序	 
void TIM1_BRK_TIM9_IRQHandler(void)
{ 	
		if((TIM9CH1_CAPTURE_STA&0X80)==0)//还未成功捕获	
		{
			if(TIM_GetITStatus(TIM9, TIM_IT_Update) != RESET)//溢出
			{	     
				if(TIM9CH1_CAPTURE_STA&0X40)//已经捕获到高电平了
				{
					if((TIM9CH1_CAPTURE_STA&0X3F)==0X1F)//高电平太长了		
					{
						TIM9CH1_CAPTURE_STA|=0X80;		//标记成功捕获了一次
						TIM9CH1_CAPTURE_VAL=0XFFFFFFFF;
						dis1=0X1F; 
						dis1*=0XFFFFFFFF;		 		         //溢出时间总和
						dis1+=TIM9CH1_CAPTURE_VAL;
						TIM9CH1_CAPTURE_STA=0;
						TIM9CH1_CAPTURE_VAL=0;
					}else TIM9CH1_CAPTURE_STA++;
				}	 
			}
			if(TIM_GetITStatus(TIM9, TIM_IT_CC1) != RESET)//捕获1发生捕获事件
			{	
				if(TIM9CH1_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
				{
					TIM9CH1_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
					TIM9CH1_CAPTURE_VAL=TIM_GetCapture1(TIM9);//获取当前的捕获值.
					TIM_OC1PolarityConfig(TIM9,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
					dis1=TIM9CH1_CAPTURE_STA&0X3F; 
					dis1*=0XFFFFFFFF;		 		         //溢出时间总和
					dis1+=TIM9CH1_CAPTURE_VAL;
					TIM9CH1_CAPTURE_STA=0;
					TIM9CH1_CAPTURE_VAL=0;
				}else  								//还未开始,第一次捕获上升沿
				{
					TIM9CH1_CAPTURE_STA=0;			//清空
					TIM9CH1_CAPTURE_VAL=0;
					TIM9CH1_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
					TIM_Cmd(TIM9,DISABLE ); 	//关闭定时器9
					TIM_SetCounter(TIM9,0);
					TIM_OC1PolarityConfig(TIM9,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
					TIM_Cmd(TIM9,ENABLE ); 	//使能定时器9
				}		    
			}			     	    					   
		}
		TIM_ClearITPendingBit(TIM9, TIM_IT_CC1|TIM_IT_Update); //清除中断标志位
}

//定时器10中断服务程序	 
void TIM1_UP_TIM10_IRQHandler(void)
{ 		    
		if((TIM10CH1_CAPTURE_STA&0X80)==0)//还未成功捕获	
		{
			if(TIM_GetITStatus(TIM10, TIM_IT_Update) != RESET)//溢出
			{	     
				if(TIM10CH1_CAPTURE_STA&0X40)//已经捕获到高电平了
				{
					if((TIM10CH1_CAPTURE_STA&0X3F)==0X1F)//高电平太长了
					{
						TIM10CH1_CAPTURE_STA|=0X80;		//标记成功捕获了一次
						TIM10CH1_CAPTURE_VAL=0XFFFFFFFF;
						dis2=0X1F; 
						dis2*=0XFFFFFFFF;		 		         //溢出时间总和
						dis2+=TIM10CH1_CAPTURE_VAL;
						TIM10CH1_CAPTURE_STA=0;
						TIM10CH1_CAPTURE_VAL=0;
					}else TIM10CH1_CAPTURE_STA++;
				}	 
			}
			if(TIM_GetITStatus(TIM10, TIM_IT_CC1) != RESET)//捕获1发生捕获事件
			{	
				if(TIM10CH1_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
				{	  			
					TIM10CH1_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
					TIM10CH1_CAPTURE_VAL=TIM_GetCapture1(TIM10);//获取当前的捕获值.
					TIM_OC1PolarityConfig(TIM10,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
					dis2=TIM10CH1_CAPTURE_STA&0X3F; 
					dis2*=0XFFFFFFFF;		 		         //溢出时间总和
					dis2+=TIM10CH1_CAPTURE_VAL;
					TIM10CH1_CAPTURE_STA=0;
					TIM10CH1_CAPTURE_VAL=0;
				}else  								//还未开始,第一次捕获上升沿
				{
					TIM10CH1_CAPTURE_STA=0;			//清空
					TIM10CH1_CAPTURE_VAL=0;
					TIM10CH1_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
					TIM_Cmd(TIM10,DISABLE ); 	//关闭定时器10
					TIM_SetCounter(TIM10,0);
					TIM_OC1PolarityConfig(TIM10,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
					TIM_Cmd(TIM10,ENABLE ); 	//使能定时器10
				}		    
			}			     	    					   
		}
		TIM_ClearITPendingBit(TIM10, TIM_IT_CC1|TIM_IT_Update); //清除中断标志位
}

void Ultrasound_trig_Init(void){
	GPIO_InitTypeDef GPIO_InitStructure;
 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//使能PORTE时钟	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //下拉
	GPIO_Init(GPIOE,&GPIO_InitStructure); //初始化PE5

	GPIO_ResetBits(GPIOE,GPIO_Pin_2 | GPIO_Pin_3);
}
