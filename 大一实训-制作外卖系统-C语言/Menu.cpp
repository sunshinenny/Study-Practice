#include"Type.h" 
#include"Function.h"
//-------------------�˵�--------------------------
void Menu(SqList &L,MenuList &L1,SqQueue &Q,AMGraph &G,int choice,int flag)
{
	while(1)//�޸ĳ���Ŀ��ʱ�� ���԰Ѳ˵��б����ǰ���ж��� 
	{ 	
		system("color fc");
      	cout<<"*********************************************************"<<endl;
	  	cout<<"1.�ϰ� 			2.�������� 	3.���Ͷ���"<<endl; 
		cout<<"4.��������ά�� 		5.ͳ�� 		0.�°�"<<endl;
	  	cout<<"*********************************************************"<<endl;
	  	cout<<"������ѡ��(0~5)��";
      	cin>>choice;
	  switch(choice)
	  {
		case 1:
			if(flag==1)	{cout<<"��ֹ�ظ��ϰ࣡"<<endl;}
			else if(ReadFile(L,G,Q)==1&&ReadMenu(L1)==1)
			{cout<<"���ݶ�ȡ��ϣ�\n��ӭʹ�ñ�ϵͳ��"<<endl<<endl;
			flag=1;}
			break;
			
		case 2:
			if(flag==0)
			cout<<"����δ�ϰ࣬���ܽ��ж�������"<<endl; 
		else
		{
			int o_choice;
			cout<<"-----------------------------------------"<<endl;
			cout<<"1.���ܶ���      2.��ѯ����     3.��ʾ����"<<endl;
			cout<<"-----------------------------------------"<<endl; 
			cin>>o_choice;
				switch(o_choice)
				{
					case 1:
					{	
						LNode *p;
						p=L1->next;//�ײ���Ϣ������ 
							
						int addressnum;
						cout<<"�ײ���Ϣ:"<<endl<<endl;
		   				cout<<"�ײͱ��     �ײ�����	       �ײ�����             	    �ײͼ۸�״̬����Ԥ��/����Ԥ����"<<endl;
		   				
						while(p!=NULL)
						{//���������ײ���Ϣ
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
					    // tm�����ʽ��ʱ��
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

						cout<<"�������ײͱ�ţ�";cin>>o_num_input;				
						while(p->next!=NULL)
						{
							if(p->num==o_num_input) {flag_num=1;if(p->cond==1) flag_cond=1;break;}
							else p=p->next;
						}
						
						if(flag_num==1&&flag_cond==1)
						{
							L.elem[L.length].M.o_num=o_num_input;cout<<endl; 
							cout<<"�����붩��������"; cin>>L.elem[L.length].M.o_nums;cout<<endl;
							cout<<"�����붩���˵�������";cin>>L.elem[L.length].M.p_name; cout<<endl;
							cout<<"�����붩���˵ĵ绰��";cin>>L.elem[L.length].M.p_phone;
							
							cout<<endl;
							//�����ַ�ÿͻ�ѡ�� 
							cout<<"1\t������У��"<<endl;cout<<"2\t������У��"<<endl;
							cout<<"3\t����С��"<<endl;cout<<"4\t����Ѻ�"<<endl;
							cout<<"5\t��ͨ��԰"<<endl;cout<<"6\t���ֿ���"<<endl;
							cout<<"7\t���Ĳ���"<<endl;cout<<"8\t�����԰"<<endl;
							cout<<"9\t��ƽ����"<<endl;cout<<"10\t�����"<<endl<<endl;
							
						
							cout<<"�����붩�͵�ַ��";cin>>addressnum;
							
							L.elem[L.length].M.o_cond=1;//Ĭ��Ϊ�ѽ��գ�δ���� 
							
							if(addressnum<1||addressnum>10)
							{
								cout<<"�����ڴ˵�ַ��������"<<endl;
							}
							else
							{ 
									if(addressnum==1) L.elem[L.length].M.address="������У��";
									if(addressnum==2) L.elem[L.length].M.address="������У��";
									if(addressnum==3) L.elem[L.length].M.address="����С��";
									if(addressnum==4) L.elem[L.length].M.address="����Ѻ�";
									if(addressnum==5) L.elem[L.length].M.address="��ͨ��԰";
									if(addressnum==6) L.elem[L.length].M.address="���ֿ���";
									if(addressnum==7) L.elem[L.length].M.address="���Ĳ���";
									if(addressnum==8) L.elem[L.length].M.address="�����԰";
									if(addressnum==9) L.elem[L.length].M.address="��ƽ����";
									if(addressnum==10) L.elem[L.length].M.address="�����";
				
								ElemType e;
								e=L.elem[L.length];
								EnQueue(Q,e);//��� 
								L.length++;
							}
						}
						
						else 
						{
							cout<<endl<<"�����ڴ��ײͣ�����ײ��޷�Ԥ�����������ԣ�"<<endl<<endl;
						} 
					
						break;
				}
		
		
					case 2:
					{	cout<<"--------------------------------------------------------"<<endl;
						cout<<"1.��������Ų�ѯ    2.��������������ѯ  3.�������˵绰��ѯ"<<endl;
						cout<<"--------------------------------------------------------"<<endl;
						int choice1;
						cout<<"��ѡ��"<<endl; 
						cin>>choice1; 
						string num0;
						switch(choice1)
						{
							case 1:
								cout<<"��������Ҫ��ѯ�Ķ�����ţ�"<<endl;
								cin>>num0;
								Search_o_ID(L,num0);
								cout<<endl;
								break;
							
							case 2: 						
								cout<<"��������Ҫ��ѯ�Ķ�����������"<<endl;
								cin>>num0;
								Search_p_name(L,num0);
								cout<<endl;
								 break; 
							
							case 3: 						
								cout<<"��������Ҫ��ѯ�Ķ����˵绰��"<<endl;
								cin>>num0;
								Search_p_phone(L,num0);
								cout<<endl;
								break;
							default:cout<<"�������������"<<endl;				
							
						}
						
						break; 
					} 
						
						case 3:PrintAllList(L);break;
						default:cout<<"�������������"<<endl;								
				}
						
				break;		
		}break; 
	 
	 			case 3:{			
					 if(flag==0)	cout<<"����δ�ϰ࣬���ܽ��ж������ͣ�"<<endl;
						else SendOrder(Q,L,G);
						break;
					}
					case 4:{
						if(flag==0)	cout<<"����δ�ϰ࣬���ܽ��л�����Ϣ����"<<endl;	
						else OrderManagement(L,Q,L1);
						break;
					} 
					case 5:{
						if(flag==0)	cout<<"����δ�ϰ࣬���ܽ���ͳ��"<<endl;
						else StatisticsOrder(L,L1);
						break;
					} 					
					case 0:{
						if(flag==0)	
						{	
							cout<<"����δ�ϰ࣬�����°࣡"<<endl;	
							cout<<"�Ƿ��˳�ϵͳ��  yes/no"<<endl;
							string off_choice;
							cin>>off_choice;
							if(off_choice=="yes") exit(0);
						}
						else OffWork(L,L1);
						break;
					}
					default:cout<<"�������������"<<endl;	
		}
	   system("pause");//�ȴ� 
	   system("cls");//����
	
	} exit(0);
}



