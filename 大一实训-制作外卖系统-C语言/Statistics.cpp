#include"Type.h" 
#include"Function.h"

void StatisticsOrder(SqList L,MenuList L1)
{
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"1.ͳ�Ƶ��충��    	  2.ͳ�Ƶ��¶���"<<endl;
	cout<<"--------------------------------------------------------"<<endl;
	int Statistics_choice;
	cout<<"������ѡ���"; cin>>Statistics_choice;
	switch(Statistics_choice)
	{
		case 1:StatisticsDay(L,L1);break;
		case 2:StatisticsMonth(L,L1);break;
		default:cout<<"�������������"<<endl;
	}
}

void StatisticsMonth(SqList &L,MenuList L1)
{//���ײͱ�š������ͽ�����Ϣ������ʾ�����Ҫ���ײ��������н������С�
  	int sum=0;
	string s;
    time_t time_T;
    time_T = time(NULL);
	LNode *p;
	p=L1;
    struct tm *tmTime;
    //--------��ȡϵͳʱ��ĺ���----- 
    tmTime = localtime(&time_T);
	char strTime[100]; char strTime1[100];  char strTime2[100]; char strTime3[100]; char strTime4[100];
	const char *format2="%Y"; const char *format3="%m";
    char year[10]; char month[10]; char day[10]; 
	strftime(year, sizeof(strTime), format2, tmTime);
    strftime(month, sizeof(strTime1), format3, tmTime);
  	//���ö������ײ���Ϣ
  	Statistics_month Order_month[50];
  	int O_num=0; 
 	while(p!=NULL)
	 {
	 	Order_month[O_num].name=p->num;
	 	Order_month[O_num].price=p->price;
	 	O_num++;
	  	p=p->next;
	  }//ͳ��һ���ж������ײ� 

 	int i;
 	for(i=0;i<L.length;i++)
 	{
	 	for(int j=0;j<O_num;j++)
		{
			if(L.elem[i].M.t_year==year&&L.elem[i].M.t_month==month&&L.elem[i].M.o_num==Order_month[j].name)
	 		{			
				Order_month[j].t_nums=L.elem[i].M.o_nums+Order_month[j].t_nums;	//�洢 ��ͳ�ƶ��������� �������ܶ����� 
				Order_month[j].year=year;	 
				Order_month[j].month=month;	
				break;	
		 	}
  		}
}		
		cout<<"�ײͱ��"<<setw(25)<<"�ײ�����"<<setw(28)<<"�ײ��ܽ��"<<endl;
		 
	
		Statistics_month t;


	for(i=0;i<O_num;i++)
	{//����������//ð������ 
		for(int j=0;j<O_num-1;j++)
		{
			if(	Order_month[j].t_nums<Order_month[i].t_nums)
				{t=Order_month[j];Order_month[j]=Order_month[i];Order_month[i]=t;}
		}
	}
	

	
	for(int j=0;j<O_num;j++) 
	{//������ 
		if(Order_month[j].year==year&&Order_month[j].month==month) 
 			cout<<Order_month[j].name<<setw(25)<<Order_month[j].t_nums<<setw(28)<<(Order_month[j].price*Order_month[j].t_nums)<<endl;
		
	}
 
	for(i=0;i<O_num;i++)
	{
		 	
		sum=Order_month[i].price*Order_month[i].t_nums+sum; 
		 	
	} 
	cout<<"�������۶�Ϊ��"<<sum<<endl<<endl; 

}

void StatisticsDay(SqList L,MenuList L1)
{//���ײͱ�š������ͽ�����Ϣ������ʾ�����Ҫ���ײ��������н������С�
 	int sum=0;
	string s;
    time_t time_T;
    time_T = time(NULL);
//----------------------ʱ�亯������ȡ��ǰ��----------------- 
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

 	cout<<setw(12)<<"�������"<<setw(18)<<"	�ײͱ��"<<setw(12)<<"  ����״̬��1/0)"<<setw(12)<<"��� "<<endl;
	int i=0;
	for (i=0;i<L.length;i++)
	{//ƥ�����Ա��������еĶ������ �������ܼ� 
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
 	
 	cout<<endl<<"���������۶�Ϊ��"<<sum<<endl;    		
}


