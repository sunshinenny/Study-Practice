#include"Type.h" 
#include"Function.h"
//-------------------菜单--------------------------
void Menu(SqList &L,MenuList &L1,SqQueue &Q,AMGraph &G,int choice,int flag)
{
	while(1)//修改成项目的时候 可以把菜单列表放入前方判断中 
	{ 	
		system("color fc");
      	cout<<"*********************************************************"<<endl;
	  	cout<<"1.上班 			2.订单管理 	3.派送订单"<<endl; 
		cout<<"4.基础数据维护 		5.统计 		0.下班"<<endl;
	  	cout<<"*********************************************************"<<endl;
	  	cout<<"请输入选项(0~5)：";
      	cin>>choice;
	  switch(choice)
	  {
		case 1:
			if(flag==1)	{cout<<"禁止重复上班！"<<endl;}
			else if(ReadFile(L,G,Q)==1&&ReadMenu(L1)==1)
			{cout<<"数据读取完毕！\n欢迎使用本系统！"<<endl<<endl;
			flag=1;}
			break;
			
		case 2:
			if(flag==0)
			cout<<"您还未上班，不能进行订单管理！"<<endl; 
		else
		{
			int o_choice;
			cout<<"-----------------------------------------"<<endl;
			cout<<"1.接受订单      2.查询订单     3.显示订单"<<endl;
			cout<<"-----------------------------------------"<<endl; 
			cin>>o_choice;
				switch(o_choice)
				{
					case 1:
					{	
						LNode *p;
						p=L1->next;//套餐信息的链表 
							
						int addressnum;
						cout<<"套餐信息:"<<endl<<endl;
		   				cout<<"套餐编号     套餐名称	       套餐描述             	    套餐价格状态（可预定/不可预定）"<<endl;
		   				
						while(p!=NULL)
						{//用来遍历套餐信息
							cout<<setw(6)<<p->num  
								<<setw(16)<<p->name   
								<<setw(30)<<p->conte 
								<<setw(15)<<p->price
								<<setw(15)<<p->cond<<endl;
							p=p->next; 
						}	
//---------------------------------------------------------------------------						
						
						string s;
					    time_t time_T;
					    time_T = time(NULL);
					
					    struct tm *tmTime;
					    // tm对象格式的时间
					    tmTime = localtime(&time_T);
					    const char *format="%Y-%m-%d%H:%M:%S"; const char *format1="%Y%m%d%H%M%S";
					    char strTime[100]; char strTime1[100];
					    
					    strftime(strTime, sizeof(strTime), format, tmTime);
					    strftime(strTime1, sizeof(strTime1), format1, tmTime);
						L.elem[L.length].M.o_ID=strTime1;
						L.elem[L.length].M.o_time=strTime;
						
						const char *Count_year="%Y";
						char year[5];
						strftime(year,sizeof(year), Count_year, tmTime);
						L.elem[L.length].M.t_year=year;
						
						const char *Count_month="%m";
						char month[5];
						strftime(month,sizeof(month), Count_month, tmTime);
						L.elem[L.length].M.t_month=month;
						
						const char *Count_day="%d";
						char day[5];
						strftime(day,sizeof(day), Count_day, tmTime);
						L.elem[L.length].M.t_day=day;
//------------------------------------------------------------------------							
						string o_num_input;
						p=L1->next;
						int flag_num=0;
						int flag_cond=0; 

						cout<<"请输入套餐编号：";cin>>o_num_input;				
						while(p->next!=NULL)
						{
							if(p->num==o_num_input) {flag_num=1;if(p->cond==1) flag_cond=1;break;}
							else p=p->next;
						}
						
						if(flag_num==1&&flag_cond==1)
						{
							L.elem[L.length].M.o_num=o_num_input;cout<<endl; 
							cout<<"请输入订餐数量："; cin>>L.elem[L.length].M.o_nums;cout<<endl;
							cout<<"请输入订餐人的姓名：";cin>>L.elem[L.length].M.p_name; cout<<endl;
							cout<<"请输入订餐人的电话：";cin>>L.elem[L.length].M.p_phone;
							
							cout<<endl;
							//输出地址让客户选择 
							cout<<"1\t华航东校区"<<endl;cout<<"2\t华航西校区"<<endl;
							cout<<"3\t金桥小区"<<endl;cout<<"4\t阳光佳和"<<endl;
							cout<<"5\t运通家园"<<endl;cout<<"6\t格林郡府"<<endl;
							cout<<"7\t华夏铂宫"<<endl;cout<<"8\t锦绣家园"<<endl;
							cout<<"9\t和平丽景"<<endl;cout<<"10\t万向城"<<endl<<endl;
							
						
							cout<<"请输入订餐地址：";cin>>addressnum;
							
							L.elem[L.length].M.o_cond=1;//默认为已接收，未派送 
							
							if(addressnum<1||addressnum>10)
							{
								cout<<"不存在此地址，请重试"<<endl;
							}
							else
							{ 
									if(addressnum==1) L.elem[L.length].M.address="华航东校区";
									if(addressnum==2) L.elem[L.length].M.address="华航西校区";
									if(addressnum==3) L.elem[L.length].M.address="金桥小区";
									if(addressnum==4) L.elem[L.length].M.address="阳光佳和";
									if(addressnum==5) L.elem[L.length].M.address="运通家园";
									if(addressnum==6) L.elem[L.length].M.address="格林郡府";
									if(addressnum==7) L.elem[L.length].M.address="华夏铂宫";
									if(addressnum==8) L.elem[L.length].M.address="锦绣家园";
									if(addressnum==9) L.elem[L.length].M.address="和平丽景";
									if(addressnum==10) L.elem[L.length].M.address="万向城";
				
								ElemType e;
								e=L.elem[L.length];
								EnQueue(Q,e);//入队 
								L.length++;
							}
						}
						
						else 
						{
							cout<<endl<<"不存在此套餐（或该套餐无法预定），请重试！"<<endl<<endl;
						} 
					
						break;
				}
		
		
					case 2:
					{	cout<<"--------------------------------------------------------"<<endl;
						cout<<"1.按订单编号查询    2.按订餐人姓名查询  3.按订餐人电话查询"<<endl;
						cout<<"--------------------------------------------------------"<<endl;
						int choice1;
						cout<<"请选择："<<endl; 
						cin>>choice1; 
						string num0;
						switch(choice1)
						{
							case 1:
								cout<<"请输入你要查询的订单编号："<<endl;
								cin>>num0;
								Search_o_ID(L,num0);
								cout<<endl;
								break;
							
							case 2: 						
								cout<<"请输入你要查询的订单人姓名："<<endl;
								cin>>num0;
								Search_p_name(L,num0);
								cout<<endl;
								 break; 
							
							case 3: 						
								cout<<"请输入你要查询的订单人电话："<<endl;
								cin>>num0;
								Search_p_phone(L,num0);
								cout<<endl;
								break;
							default:cout<<"输入错误，请重试"<<endl;				
							
						}
						
						break; 
					} 
						
						case 3:PrintAllList(L);break;
						default:cout<<"输入错误，请重试"<<endl;								
				}
						
				break;		
		}break; 
	 
	 			case 3:{			
					 if(flag==0)	cout<<"您还未上班，不能进行订单派送！"<<endl;
						else SendOrder(Q,L,G);
						break;
					}
					case 4:{
						if(flag==0)	cout<<"您还未上班，不能进行基础信息管理！"<<endl;	
						else OrderManagement(L,Q,L1);
						break;
					} 
					case 5:{
						if(flag==0)	cout<<"您还未上班，不能进行统计"<<endl;
						else StatisticsOrder(L,L1);
						break;
					} 					
					case 0:{
						if(flag==0)	
						{	
							cout<<"您还未上班，不能下班！"<<endl;	
							cout<<"是否退出系统？  yes/no"<<endl;
							string off_choice;
							cin>>off_choice;
							if(off_choice=="yes") exit(0);
						}
						else OffWork(L,L1);
						break;
					}
					default:cout<<"输入错误，请重试"<<endl;	
		}
	   system("pause");//等待 
	   system("cls");//清屏
	
	} exit(0);
}



