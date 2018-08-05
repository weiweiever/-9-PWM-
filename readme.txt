暑假机器人（避障车）：
	3路PWM输出：	
				1.PA7  TIM14 CH1
				2.PA6  TIM13 CH1
				3.PB14 TIM12 CH1
	3路编码器读取：	
				1.PB6 PB7 TIM4			3900/r
				2.PC6 PC7 TIM3
				3.PA0 PA1 TIM5
	2路超声波捕获
				1.PE5 TIM9  CH1
				2.PB8 TIM10 CH1
	
	独立IO：
		超声波触发Trig：
				PE2 Trig1
				PE3 Trig2
		电机方向控制：
				1. PE8 PE9
				2. PE10 PE11
				3. PE12 PE13
				
	
辅助：串口：USART1 PA9 PA10