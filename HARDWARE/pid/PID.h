#ifndef __PID_H
#define __PID_H
#include "sys.h"

typedef struct 
{
	int target;//设定目标
	
	float Kp ;//比例常数
	float Ki;//积分常数
	float Kd;//微分常数
	
	int sum_error;//误差累计
	int last_error;
	int prev_error;
	
}PIDtypedef;


void PIDxInit(PIDtypedef* PIDx);		//初始化，参数清零清零
int  PIDcalc(PIDtypedef*PIDx,u16 nextpoint);	   //PID计算
void PID_setTarget(PIDtypedef*PIDx,u16 setvalue);  //设定 PID预期值
void PID_set(PIDtypedef *PIDx,float Kp,float Ki,float Kd);//设定PID  kp ki kd三个参数

#endif
