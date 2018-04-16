#include"Type.h" 
#include"Function.h"
//-------------------线性表---------------------------
Status Node_InitList(MenuList &L1) //1是链表 
{//链表的初始化
	L1=new LNode;
	L1->next=NULL;
	return OK;	
} 

Status InitList(SqList &L)
{//顺序表构建一个空的顺序表L 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem)
		return ERROR;
	L.length=0;
	return OK;
}

Status ListInsert(SqList &L,int i,ElemType e) 
{//在顺序表指定位置中插入一条内容 
	int j;
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	++L.length;
	return OK;
 	
}

Status NodeInsert(MenuList &L1,int i,T_ElemType e) 
{//在带头结点的单链表L中第i个位置插入值为e的新结点 

	LNode *p,*s;
	p=L1;
	s=new LNode;//建立新的链表 

	s->cond=e.Tcond  ;
	s->conte=e.Tconte  ;
	s->name =e. Tname ;
	s->num =e. Tnum  ;
	s->price=e.Tprice ;
	s->next=p->next;
	p->next=s;
	
	return OK; 

} 
  
Status ListDelete(SqList &L,int i)
{//顺序表的删除
	if((i<1||i>L.length)) return ERROR;
	for(int j=1;j<=L.length;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}   
 


