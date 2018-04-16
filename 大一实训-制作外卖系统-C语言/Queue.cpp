#include"Type.h" 
#include"Function.h"

//-------------------队列的函数---------------------------
Status InitQueue(SqQueue &Q)        //队列初始化 
{
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem)exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue &Q)        //长度 
{
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

Status EnQueue(SqQueue &Q,ElemType e)  //入队 
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue &Q,ElemType e)  //出队 
{
	int o_addressnum;
	if(Q.front==Q.rear) return ERROR;

	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 

ElemType GetHead(SqQueue Q)      //取队首元素 
{
	if(Q.front!=Q.rear)
		return Q.elem[Q.front];
}

Status FinishOrder(SqQueue &Q,ElemType &e,SqList &L,AMGraph &G)  //出队 ·全功能版·用于订单派送而不是信息管理 
{
	int o_addressnum;
	if(Q.front==Q.rear) return ERROR;//判断队列是否为空 

	e=Q.elem[Q.front];
	
	//将e的第一个信息传递给查找 然后找到具体位置 然后将其状态修改为 0 
	L.elem[Search_o_ID(L,e.M.o_ID)].M.o_cond=0;
	
	if(e.M.address=="华航东校区") o_addressnum=0;
	if(e.M.address=="华航西校区") o_addressnum=1;
	if(e.M.address=="金桥小区") o_addressnum=2;
	if(e.M.address=="阳光佳和") o_addressnum=3;
	if(e.M.address=="运通家园") o_addressnum=4;
	if(e.M.address=="格林郡府") o_addressnum=5;
	if(e.M.address=="华夏铂宫") o_addressnum=6;
	if(e.M.address=="锦绣家园") o_addressnum=7;
	if(e.M.address=="和平丽景") o_addressnum=8;	
	if(e.M.address=="万向城") 	o_addressnum=9;		
	SendOrder(G,o_addressnum);
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 


