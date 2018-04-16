#include"Type.h" 
#include"Function.h"
//-------------------输出函数--------------------------
int PrintList(SqList L,int i)// 输出查找订单 
{
	cout<<"______________________________________________________________________________________________________________"<<endl;
   cout<<"订单编号 	套餐编号 套餐数量 订餐人姓名  订餐人电话	派送地址     下单时间      状态（已接收/已派送）"<<endl;
  	
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


int PrintAllList(SqList L)//输出全部订单 
{
	cout<<"______________________________________________________________________________________________________________"<<endl;
   	cout<<"订单编号 	套餐编号 套餐数量 订餐人姓名  订餐人电话	派送地址     下单时间      状态（已接收/已派送）"<<endl<<endl;
	  	
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


