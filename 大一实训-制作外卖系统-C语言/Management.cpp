#include"Type.h" 
#include"Function.h"
//------------------基础信息管理----------------------------- 
void SendOrder(SqQueue &Q,SqList &L,AMGraph &G)
{
	ElemType e;

	if(FinishOrder(Q,e,L,G)==OK)
	{
	cout<<"订单派送成功！"<<endl<<endl;
	}
	else cout<<"全部订单派送完成"<<endl;	
}

void OrderManagement(SqList &L,SqQueue &Q,MenuList &L1)
{
	int Management_choice;
	
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"1.添加套餐    2.删除套餐  3.修改套餐内容"<<endl;	
	cout<<"4.添加订单    5.删除订单  6.修改订单内容"<<endl;
	cout<<"--------------------------------------------------------"<<endl;	
	cout<<"请输入：";cin>>Management_choice;
	switch(Management_choice) 
	{
		case 1:Addpackage(L1,L);break; 
		case 2:Deletepackage(L1);break;
		case 3:Changepackage(L1);break;		
		case 4:AddOrder(L,Q);break;
		case 5:DeleteOrder(L,Q);break;
		case 6:ChangeOrder(L,Q);break;
		default:cout<<"输入错误，请重试"<<endl;
	}
	
	
}

int PrintfOrder(MenuList L1)
	{
	cout<<"套餐信息:"<<endl<<endl;
	LNode *p; p=L1->next; 
	cout<<"套餐编号     套餐名称	       套餐描述             	    套餐价格状态（可预定/不可预定）"<<endl;
	
	while(p!=NULL)
	{
		cout<<setw(6)<<p->num  
		<<setw(16)<<p->name   
		<<setw(30)<<p->conte 
		<<setw(15)<<p->price
		<<setw(15)<<p->cond<<endl;
		p=p->next; 
	}
	return 0; 
	} 
void  Addpackage(MenuList &L1,SqList L) //  添加套餐 
{
	T_ElemType e; int i=0;
		
		int flag;
		int t_num_num;
		char int_string[10];
		string t_num;string add;

//--------------自动生成套餐编号 
	while(1)
	{ 
		flag=1;
		srand(time(0));
		t_num_num=rand()%1000;
		if(t_num_num<10)
		{
			sprintf(int_string,"%d",t_num_num);
			t_num=int_string;
			add="M00"+t_num;
			e.Tnum=add;
		}
		
		if(t_num_num>10&&t_num_num<100)
		{
			sprintf(int_string,"%d",t_num_num);
			t_num=int_string;
			add="M0"+t_num;	
			e.Tnum=add;						
		}
		
		if(t_num_num>100&&t_num_num<1000)
		{
			sprintf(int_string,"%d",t_num_num);
			t_num=int_string;
			add="M"+t_num;	
			e.Tnum=add;					
		}
		
		for(i=0;i<L.length;i++)//判断是否与原有编号重复 
			if(L.elem[i].M.o_num==e.Tnum) flag=0;
			
		if(flag==0) continue;//如果重复，再重新生成 
		
		else 
		{
			cout<<"套餐编号已自动生成  "<<e.Tnum<<endl<<endl;
			break;
		}
	}	
//--------------------------------	
		cout<<"请输入套餐名称；"<<endl;
		cin>>e.Tname;
		cout<<"请输入套餐描述："<<endl;
		cin>>e.Tconte;
		cout<<"请输入套餐价格："<<endl;
		cin>>e.Tprice;
		
	while(1)
	{//判断套餐状态是否符合条件 
		cout<<"请输入套餐状态（可预定为 1，不可预定为 0）"<<endl;
		cin>>e.Tcond;
		if(e.Tcond==1||e.Tcond==0) break;
		else
		{
			cout<<"输入错误，请重试！"<<endl;
			continue;	
		} 
	} 
		string s1;
		int a;

	if(NodeInsert(L1,i,e)==OK)
	cout<<"套餐添加成功！"; 


}

void  Changepackage(MenuList &L1)  //  修改套餐 
{
	LNode *p;
	p=L1;
	T_ElemType e; 
	PrintfOrder(L1);
	int flag=1;
	cout<<"请输入你要修改的套餐的编号：";
	cin>>e.Tnum;
	while(p!=NULL)
	{
		
		if(p->num==e.Tnum)
		{	
		flag=0;
		cout<<"请输入新的套餐名称："<<endl;
		cin>>p->name;
		cout<<"请输入新的套餐描述："<<endl;
		cin>>p->conte;
		cout<<"请输入新的套餐价格："<<endl;
		cin>>p->price; 			
		}
		p=p->next;
	}
	if(flag==1) cout<<"没有此订单，请重试!"<<endl;
 } 

void  Deletepackage(MenuList &L1)  //删除套餐 
{
		LNode *p;
		p=L1;
		T_ElemType e; 
		PrintfOrder(L1);
		int flag=1;
		cout<<"请输入你要修改的套餐的编号：";
		cin>>e.Tnum;
		while(p!=NULL)
		{
			if(p->num==e.Tnum)
			{	
				cout<<"请输入要修改的状态：（可预定为 1，不可预定为 0）"<<endl;
				int i;
				cin>>i;
				flag=0;
				if(i==p->cond)
				cout<<"订单当前状态与所修改状态相同，无需更改！";
				
				else 
				{
					p->cond=i;  cout<<"套餐信息修改完成！"; 
				}
			}
			p=p->next;
	}
	if(flag==1) cout<<"没有此订单，请重试！"<<endl;
	
}

Status AddOrder(SqList &L,SqQueue &Q)//在指定位置添加订单 
{
	ElemType e;	
	int i;
	cout<<"当前最后一行为："<<L.length<<endl<<"请输入想插入的行数:"	;
	cin>>i;	
	if(i>0&&i<=L.length) 
	{ 
		string s;
	    time_t time_T;
	    time_T = time(NULL);
	
	    struct tm *tmTime;
	    // tm对象格式的时间
	    tmTime = localtime(&time_T);
	    const char *format="%Y-%m-%d%H:%M:%S"; const char *format1="%Y%m%d%H%M%S";
	    char strTime[100]; char strTime1[100];
	    
	    strftime(strTime1, sizeof(strTime1), format1, tmTime);
	    strftime(strTime, sizeof(strTime), format, tmTime);
		e.M.o_ID=strTime1; 
		e.M.o_time=strTime;
	
		int addressnum;
		
		string o_num_input;
		cout<<"请输入套餐编号："; cin>>o_num_input;

		e.M.o_num=o_num_input;cout<<endl; 
		cout<<"请输入订餐数量："; cin>>e.M.o_nums;cout<<endl;
		cout<<"请输入订餐人的姓名：";cin>>e.M.p_name; cout<<endl;
		cout<<"请输入订餐人的电话：";cin>>e.M.p_phone;
		
		cout<<"1\t华航东校区"<<endl;cout<<"2\t华航西校区"<<endl;
		cout<<"3\t金桥小区"<<endl;cout<<"4\t阳光佳和"<<endl;
		cout<<"5\t运通家园"<<endl;cout<<"6\t格林郡府"<<endl;
		cout<<"7\t华夏铂宫"<<endl;cout<<"8\t锦绣家园"<<endl;
		cout<<"9\t和平丽景"<<endl;cout<<"10\t万向城"<<endl;
		//输出地址让客户选择 
		
		cout<<"请输入订餐地址：";cin>>addressnum;
		e.M.o_cond=1;//默认为已接收，未派送 
	
				if(addressnum==1) e.M.address="华航东校区";
				if(addressnum==2) e.M.address="华航西校区";
				if(addressnum==3) e.M.address="金桥小区";
				if(addressnum==4) e.M.address="阳光佳和";
				if(addressnum==5) e.M.address="运通家园";
				if(addressnum==6) e.M.address="格林郡府";
				if(addressnum==7) e.M.address="华夏铂宫";
				if(addressnum==8) e.M.address="锦绣家园";
				if(addressnum==9) e.M.address="和平丽景";
				if(addressnum==10) e.M.address="万向城";
				
	ListInsert(L,i,e);
	
	while(Q.front!=Q.rear)	DeQueue(Q,e);
	
	for(int i=0;i<L.length;i++) EnQueue(Q,L.elem[i]);
	}
	else cout<<"没有该空位，请重试！"<<endl;
//在完成订单修改后，重新定义队列 
}

Status DeleteOrder(SqList &L,SqQueue &Q)
{
	string o_ID;
	PrintAllList(L);//显示所有订单供以选择
	 
	cout<<"请输入您想删除的订单（根据订单编号）:";
	cin>>o_ID;
	
	if(ListDelete(L,Search_o_ID(L,o_ID))==OK) cout<<"删除成功"<<endl;
	else cout<<"删除失败"<<endl;
	
	ElemType e;
	while(Q.front!=Q.rear)	DeQueue(Q,e);
	
	for(int i=0;i<L.length;i++) 
	{	
		if(L.elem[i].M.o_cond==1)
		EnQueue(Q,L.elem[i]);
		else continue;
	}
}


Status ChangeOrder(SqList &L,SqQueue &Q)
{
	string o_ID;
	int o_change_choice;
	int i;
	
	PrintAllList(L);//显示所有订单供以选择
	 
	cout<<"请输入您修改的订单（根据订单编号定位）:";
	cin>>o_ID;
	
	if(i=Search_o_ID(L,o_ID))
	{	
		cout<<"请选择您想修改的项目"<<endl;
		cout<<"1\t订单编号\t"
			<<"2\t套餐编号"<<endl
			<<"3\t套餐数量\t"
			<<"4\t订餐人姓名"<<endl
			<<"5\t订餐人电话\t"
			<<"6\t派送地址"<<endl
			<<"7\t下单时间\t"
			<<"8\t状态"<<endl;
		cin>>o_change_choice;
		switch(o_change_choice)
		{
			case 1:{
					cout<<"请输入14位编号:";
					cin>>L.elem[i].M.o_ID;
					cout<<"修改成功"<<endl;					
				break;
			}
			
			case 2:{
					cout<<"请输入套餐编号（4位，MXXX，XXX为任意数字）:";
					cin>>L.elem[i].M.o_num;
					cout<<"修改成功"<<endl;					
				break;
			}	
			
			case 3:{
					cout<<"请输入套餐数量:";
					cin>>L.elem[i].M.o_nums;
					cout<<"修改成功"<<endl;					
				break;
			}
			
			case 4:{
					cout<<"请输入订餐人姓名:";
					cin>>L.elem[i].M.p_name;
					cout<<"修改成功"<<endl;					
				break;
			}
			
			case 5:{
					cout<<"请输入订餐人电话:";
					cin>>L.elem[i].M.p_phone;
					cout<<"修改成功"<<endl;					
				break;
			}
			
			case 6:{ 							int addressnum;
												cout<<"1\t华航东校区"<<endl;cout<<"2\t华航西校区"<<endl;
												cout<<"3\t金桥小区"<<endl;cout<<"4\t阳光佳和"<<endl;
												cout<<"5\t运通家园"<<endl;cout<<"6\t格林郡府"<<endl;
												cout<<"7\t华夏铂宫"<<endl;cout<<"8\t锦绣家园"<<endl;
												cout<<"9\t和平丽景"<<endl;cout<<"10\t万向城"<<endl;
												//输出地址让客户选择 
												
												cout<<"请输入派送地址:";cin>>addressnum;
												L.elem[i].M.o_cond=1;//默认为已接收，未派送 
									
												if(addressnum==1) L.elem[i].M.address="华航东校区";
												if(addressnum==2) L.elem[i].M.address="华航西校区";
												if(addressnum==3) L.elem[i].M.address="金桥小区";
												if(addressnum==4) L.elem[i].M.address="阳光佳和";
												if(addressnum==5) L.elem[i].M.address="运通家园";
												if(addressnum==6) L.elem[i].M.address="格林郡府";
												if(addressnum==7) L.elem[i].M.address="华夏铂宫";
												if(addressnum==8) L.elem[i].M.address="锦绣家园";
												if(addressnum==9) L.elem[i].M.address="和平丽景";
												if(addressnum==10) L.elem[i].M.address="万向城";
			cout<<"修改成功"<<endl;								
	
				break;
			}
			
			case 7:{
					cout<<"请输入下单时间:";
					cin>>L.elem[i].M.o_time;
					cout<<"修改成功"<<endl;					
				break;
			}
			
			case 8:{
					cout<<"请输入订单状态（1/0）:";
					cin>>L.elem[i].M.o_cond;
					cout<<"修改成功"<<endl; 
				break;
			}
			default:cout<<"输入错误，请重试"<<endl;
																
		}
	}
} 


