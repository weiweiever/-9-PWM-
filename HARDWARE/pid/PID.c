#include "PID.h"

void PIDxInit(PIDtypedef* PIDx)
{
//PID参数初始化
 PIDx->sum_error=0;
 PIDx->last_error=0;
 PIDx->prev_error=0;
 PIDx->target=0;
}
 void PID_setTarget(PIDtypedef* PIDx,u16 setvalue)
 {
	PIDx->target=setvalue;
	PIDx->sum_error=0;
	PIDx->last_error=0;
	PIDx->prev_error=0;
	if(setvalue==0){
		PIDxInit(PIDx);
	}
 }
 
int PIDcalc(PIDtypedef *PIDx,u16 now)
{
	if(PIDx->target==0)return 0;
	int nowError,res;
	nowError=PIDx->target-now;  //当前误差
	PIDx->sum_error+=nowError;
	
	res=							  //计算
		PIDx->Kp * nowError
		+PIDx->Ki * PIDx->sum_error
		+PIDx->Kd *(nowError-PIDx->last_error);

 PIDx->last_error=nowError;
 return res;
}

void PID_set(PIDtypedef *PIDx,float Kp,float Ki,float Kd)
{
 PIDx->Kp=Kp;
 PIDx->Ki=Ki;
 PIDx->Kd=Kd; 

}

