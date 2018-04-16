#include"Type.h" 
#include"Function.h"
//-------------------查找---------------------------
int Search_o_ID(SqList L,string e)//  按订单编号查询订单 
{
	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.o_ID)

		{PrintList(L,i);f=1;break;} 
	
	}
	
	if(i==L.length&&f==0)
	cout<<"没有此订单！"<<endl<<endl; 
	return i; 
}


int Search_p_name(SqList L,string e)//按订单人姓名查询订单 
{
	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.p_name)
	{PrintList(L,i);f=1;} 
	 
	}
	if(i==L.length&&f==0)
	cout<<"没有此订单！"<<endl<<endl; 
	
}
int Search_p_phone(SqList L,string e)//按订单人的电话查询 
{

	int i;int f=0;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i].M.p_phone)
	{PrintList(L,i);f=1;} 
	 
	}
	if(i==L.length&&f==0)
	cout<<"没有此订单！"<<endl<<endl; 
	
} 


