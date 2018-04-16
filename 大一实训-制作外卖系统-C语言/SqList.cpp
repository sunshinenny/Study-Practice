#include"Type.h" 
#include"Function.h"
//-------------------���Ա�---------------------------
Status Node_InitList(MenuList &L1) //1������ 
{//����ĳ�ʼ��
	L1=new LNode;
	L1->next=NULL;
	return OK;	
} 

Status InitList(SqList &L)
{//˳�����һ���յ�˳���L 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem)
		return ERROR;
	L.length=0;
	return OK;
}

Status ListInsert(SqList &L,int i,ElemType e) 
{//��˳���ָ��λ���в���һ������ 
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
{//�ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½�� 

	LNode *p,*s;
	p=L1;
	s=new LNode;//�����µ����� 

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
{//˳����ɾ��
	if((i<1||i>L.length)) return ERROR;
	for(int j=1;j<=L.length;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
	return OK;
}   
 


