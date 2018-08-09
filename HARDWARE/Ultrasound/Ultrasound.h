#ifndef _ULTRASOUND_H
#define _ULTRASOUND_H

#include "sys.h"


#define Trig1 PEout(2)	
#define Trig2 PEout(3)

void TIM9_Ultrasound_cap_Init(u32 arr,u16 psc);
void TIM10_Ultrasound_cap_Init(u32 arr,u16 psc);
void Ultrasound_trig_Init(void);
#endif
