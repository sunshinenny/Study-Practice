#include"Type.h" 
#include"Function.h"

void StatisticsOrder(SqList L,MenuList L1)
{
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"1.统计当天订单    	  2.统计当月订单"<<endl;
	cout<<"--------------------------------------------------------"<<endl;
	int Statistics_choice;
	cout<<"请输入选择项："; cin>>Statistics_choice;
	switch(Statistics_choice)
	{
		case 1:StatisticsDay(L,L1);break;
		case 2:StatisticsMonth(L,L1);break;
		default:cout<<"输入错误，请重试"<<endl;
	}
}

void StatisticsMonth(SqList &L,MenuList L1)
{//按套餐编号、数量和金额等信息分列显示结果。要求按套餐数量进行降序排列。
  	int sum=0;
	string s;
    time_t time_T;
    time_T = time(NULL);
	LNode *p;
	p=L1;
    struct tm *tmTime;
    //--------获取系统时间的函数----- 
    tmTime = localtime(&time_T);
	char strTime[100]; char strTime1[100];  char strTime2[100]; char strTime3[100]; char strTime4[100];
	const char *format2="%Y"; const char *format3="%m";
    char year[10]; char month[10]; char day[10]; 
	strftime(year, sizeof(strTime), format2, tmTime);
    strftime(month, sizeof(strTime1), format3, tmTime);
  	//配置订单和套餐信息
  	Statistics_month Order_month[50];
  	int O_num=0; 
 	while(p!=NULL)
	 {
	 	Order_month[O_num].name=p->num;
	 	Order_month[O_num].price=p->price;
	 	O_num++;
	  	p=p->next;
	  }//统计一共有多少种套餐 

 	int i;
 	for(i=0;i<L.length;i++)
 	{
	 	for(int j=0;j<O_num;j++)
		{
			if(L.elem[i].M.t_year==year&&L.elem[i].M.t_month==month&&L.elem[i].M.o_num==Order_month[j].name)
	 		{			
				Order_month[j].t_nums=L.elem[i].M.o_nums+Order_month[j].t_nums;	//存储 月统计订单的数量 ，生成总订单数 
				Order_month[j].year=year;	 
				Order_month[j].month=month;	
				break;	
		 	}
  		}
}		
		cout<<"套餐编号"<<setw(25)<<"套餐数量"<<setw(28)<<"套餐总金额"<<endl;
		 
	
		Statistics_month t;


	for(i=0;i<O_num;i++)
	{//按降序排列//冒泡排序 
		for(int j=0;j<O_num-1;j++)
		{
			if(	Order_month[j].t_nums<Order_month[i].t_nums)
				{t=Order_month[j];Order_month[j]=Order_month[i];Order_month[i]=t;}
		}
	}
	

	
	for(int j=0;j<O_num;j++) 
	{//输出结果 
		if(Order_month[j].year==year&&Order_month[j].month==month) 
 			cout<<Order_month[j].name<<setw(25)<<Order_month[j].t_nums<<setw(28)<<(Order_month[j].price*Order_month[j].t_nums)<<endl;
		
	}
 
	for(i=0;i<O_num;i++)
	{
		 	
		sum=Order_month[i].price*Order_month[i].t_nums+sum; 
		 	
	} 
	cout<<"月总销售额为："<<sum<<endl<<endl; 

}

void StatisticsDay(SqList L,MenuList L1)
{//按套餐编号、数量和金额等信息分列显示结果。要求按套餐数量进行降序排列。
 	int sum=0;
	string s;
    time_t time_T;
    time_T = time(NULL);
//----------------------时间函数，获取当前天----------------- 
    struct tm *tmTime;
    tmTime = localtime(&time_T);
	 char strTime[100]; char strTime1[100];  char strTime2[100]; char strTime3[100]; char strTime4[100];
	const char *format2="%Y"; const char *format3="%m";  const char *format4="%d";
    char year[10]; char month[10]; char day[10]; 
	strftime(year, sizeof(strTime), format2, tmTime);
    strftime(month, sizeof(strTime1), format3, tmTime);
	strftime(day, sizeof(strTime2), format4, tmTime);
//----------------------------------------------------------- 	
 	LNode *p; int O_num=0;
 	p=L1;

 	cout<<setw(12)<<"订单编号"<<setw(18)<<"	套餐编号"<<setw(12)<<"  订单状态（1/0)"<<setw(12)<<"金额 "<<endl;
	int i=0;
	for (i=0;i<L.length;i++)
	{//匹配线性表与链表中的订单编号 ，计算总价 
		if(L.elem[i].M.t_year==year&&L.elem[i].M.t_month==month&&L.elem[i].M.t_day==day)
		{
			int Price;
			while(p!=NULL)
			{
				if(L.elem[i].M.o_num==p->num)
				{
					Price=p->price;
					break; 
				}
				p=p->next;
		}
		cout<<setw(12)<<L.elem[i].M.o_ID<<setw(16)<<L.elem[i].M.o_num<<setw(12)<<L.elem[i].M.o_cond<<setw(17)<<(L.elem[i].M.o_nums*Price)<<endl;
		
		sum=sum+L.elem[i].M.o_nums*Price;		
		}
		
	}
 	
 	cout<<endl<<"当天总销售额为："<<sum<<endl;    		
}


