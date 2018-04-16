#include"Type.h" 
#include"Function.h"

//-------------------���еĺ���---------------------------
Status InitQueue(SqQueue &Q)        //���г�ʼ�� 
{
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem)exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue &Q)        //���� 
{
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue &Q,ElemType e)  //��� 
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,ElemType e)  //���� 
{
	int o_addressnum;
	if(Q.front==Q.rear) return ERROR;

	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 

ElemType GetHead(SqQueue Q)      //ȡ����Ԫ�� 
{
	if(Q.front!=Q.rear)
		return Q.elem[Q.front];
}

Status FinishOrder(SqQueue &Q,ElemType &e,SqList &L,AMGraph &G)  //���� ��ȫ���ܰ桤���ڶ������Ͷ�������Ϣ���� 
{
	int o_addressnum;
	if(Q.front==Q.rear) return ERROR;//�ж϶����Ƿ�Ϊ�� 

	e=Q.elem[Q.front];
	
	//��e�ĵ�һ����Ϣ���ݸ����� Ȼ���ҵ�����λ�� Ȼ����״̬�޸�Ϊ 0 
	L.elem[Search_o_ID(L,e.M.o_ID)].M.o_cond=0;
	
	if(e.M.address=="������У��") o_addressnum=0;
	if(e.M.address=="������У��") o_addressnum=1;
	if(e.M.address=="����С��") o_addressnum=2;
	if(e.M.address=="����Ѻ�") o_addressnum=3;
	if(e.M.address=="��ͨ��԰") o_addressnum=4;
	if(e.M.address=="���ֿ���") o_addressnum=5;
	if(e.M.address=="���Ĳ���") o_addressnum=6;
	if(e.M.address=="�����԰") o_addressnum=7;
	if(e.M.address=="��ƽ����") o_addressnum=8;	
	if(e.M.address=="�����") 	o_addressnum=9;		
	SendOrder(G,o_addressnum);
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 


