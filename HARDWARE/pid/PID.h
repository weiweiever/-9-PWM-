#ifndef __PID_H
#define __PID_H
#include "sys.h"

typedef struct 
{
	int target;//�趨Ŀ��
	
	float Kp ;//��������
	float Ki;//���ֳ���
	float Kd;//΢�ֳ���
	
	int sum_error;//����ۼ�
	int last_error;
	int prev_error;
	
}PIDtypedef;


void PIDxInit(PIDtypedef* PIDx);		//��ʼ����������������
int  PIDcalc(PIDtypedef*PIDx,u16 nextpoint);	   //PID����
void PID_setTarget(PIDtypedef*PIDx,u16 setvalue);  //�趨 PIDԤ��ֵ
void PID_set(PIDtypedef *PIDx,float Kp,float Ki,float Kd);//�趨PID  kp ki kd��������

#endif
