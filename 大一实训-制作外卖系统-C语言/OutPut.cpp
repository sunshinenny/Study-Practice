#include"Type.h" 
#include"Function.h"
//-------------------�������--------------------------
int PrintList(SqList L,int i)// ������Ҷ��� 
{
	cout<<"______________________________________________________________________________________________________________"<<endl;
   cout<<"������� 	�ײͱ�� �ײ����� ����������  �����˵绰	���͵�ַ     �µ�ʱ��      ״̬���ѽ���/�����ͣ�"<<endl;
  	
	  cout<<setw(9)<<L.elem[i].M.o_ID 
	  <<setw(9)<<L.elem[i].M.o_num
	  <<setw(9)<<L.elem[i].M.o_nums
	  <<setw(9)<<L.elem[i].M.p_name
	  <<setw(16)<<L.elem[i].M.p_phone
	  <<setw(15)<<L.elem[i].M.address
	  <<setw(20)<<L.elem[i].M.o_time
	  <<setw(9)<<L.elem[i].M.o_cond;
	  
	  cout<<endl<<endl; 
}


int PrintAllList(SqList L)//���ȫ������ 
{
	cout<<"______________________________________________________________________________________________________________"<<endl;
   	cout<<"������� 	�ײͱ�� �ײ����� ����������  �����˵绰	���͵�ַ     �µ�ʱ��      ״̬���ѽ���/�����ͣ�"<<endl<<endl;
	  	
	for(int i=0;i<L.length;i++)
  	{ 
	  cout<<setw(9)<<L.elem[i].M.o_ID 
	  <<setw(9)<<L.elem[i].M.o_num
	  <<setw(9)<<L.elem[i].M.o_nums
	  <<setw(9)<<L.elem[i].M.p_name
	  <<setw(16)<<L.elem[i].M.p_phone
	  <<setw(15)<<L.elem[i].M.address
	  <<setw(20)<<L.elem[i].M.o_time
	  <<setw(9)<<L.elem[i].M.o_cond;
	 
	  cout<<endl<<endl; 
	} 
}


