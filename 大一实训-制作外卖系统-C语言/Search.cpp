#include"Type.h" 
#include"Function.h"
//-------------------����---------------------------
int Search_o_ID(SqList L,string e)//  ��������Ų�ѯ���� 
{
	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.o_ID)

		{PrintList(L,i);f=1;break;} 
	
	}
	
	if(i==L.length&&f==0)
	cout<<"û�д˶�����"<<endl<<endl; 
	return i; 
}


int Search_p_name(SqList L,string e)//��������������ѯ���� 
{
	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.p_name)
	{PrintList(L,i);f=1;} 
	 
	}
	if(i==L.length&&f==0)
	cout<<"û�д˶�����"<<endl<<endl; 
	
}
int Search_p_phone(SqList L,string e)//�������˵ĵ绰��ѯ 
{

	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.p_phone)
	{PrintList(L,i);f=1;} 
	 
	}
	if(i==L.length&&f==0)
	cout<<"û�д˶�����"<<endl<<endl; 
	
} 


