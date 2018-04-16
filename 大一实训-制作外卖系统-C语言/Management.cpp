#include"Type.h" 
#include"Function.h"
//------------------������Ϣ����----------------------------- 
void SendOrder(SqQueue &Q,SqList &L,AMGraph &G)
{
	ElemType e;

	if(FinishOrder(Q,e,L,G)==OK)
	{
	cout<<"�������ͳɹ���"<<endl<<endl;
	}
	else cout<<"ȫ�������������"<<endl;	
}

void OrderManagement(SqList &L,SqQueue &Q,MenuList &L1)
{
	int Management_choice;
	
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"1.����ײ�    2.ɾ���ײ�  3.�޸��ײ�����"<<endl;	
	cout<<"4.��Ӷ���    5.ɾ������  6.�޸Ķ�������"<<endl;
	cout<<"--------------------------------------------------------"<<endl;	
	cout<<"�����룺";cin>>Management_choice;
	switch(Management_choice) 
	{
		case 1:Addpackage(L1,L);break; 
		case 2:Deletepackage(L1);break;
		case 3:Changepackage(L1);break;		
		case 4:AddOrder(L,Q);break;
		case 5:DeleteOrder(L,Q);break;
		case 6:ChangeOrder(L,Q);break;
		default:cout<<"�������������"<<endl;
	}
	
	
}

int PrintfOrder(MenuList L1)
	{
	cout<<"�ײ���Ϣ:"<<endl<<endl;
	LNode *p; p=L1->next; 
	cout<<"�ײͱ��     �ײ�����	       �ײ�����             	    �ײͼ۸�״̬����Ԥ��/����Ԥ����"<<endl;
	
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
void  Addpackage(MenuList &L1,SqList L) //  ����ײ� 
{
	T_ElemType e; int i=0;
		
		int flag;
		int t_num_num;
		char int_string[10];
		string t_num;string add;

//--------------�Զ������ײͱ�� 
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
		
		for(i=0;i<L.length;i++)//�ж��Ƿ���ԭ�б���ظ� 
			if(L.elem[i].M.o_num==e.Tnum) flag=0;
			
		if(flag==0) continue;//����ظ������������� 
		
		else 
		{
			cout<<"�ײͱ�����Զ�����  "<<e.Tnum<<endl<<endl;
			break;
		}
	}	
//--------------------------------	
		cout<<"�������ײ����ƣ�"<<endl;
		cin>>e.Tname;
		cout<<"�������ײ�������"<<endl;
		cin>>e.Tconte;
		cout<<"�������ײͼ۸�"<<endl;
		cin>>e.Tprice;
		
	while(1)
	{//�ж��ײ�״̬�Ƿ�������� 
		cout<<"�������ײ�״̬����Ԥ��Ϊ 1������Ԥ��Ϊ 0��"<<endl;
		cin>>e.Tcond;
		if(e.Tcond==1||e.Tcond==0) break;
		else
		{
			cout<<"������������ԣ�"<<endl;
			continue;	
		} 
	} 
		string s1;
		int a;

	if(NodeInsert(L1,i,e)==OK)
	cout<<"�ײ���ӳɹ���"; 


}

void  Changepackage(MenuList &L1)  //  �޸��ײ� 
{
	LNode *p;
	p=L1;
	T_ElemType e; 
	PrintfOrder(L1);
	int flag=1;
	cout<<"��������Ҫ�޸ĵ��ײ͵ı�ţ�";
	cin>>e.Tnum;
	while(p!=NULL)
	{
		
		if(p->num==e.Tnum)
		{	
		flag=0;
		cout<<"�������µ��ײ����ƣ�"<<endl;
		cin>>p->name;
		cout<<"�������µ��ײ�������"<<endl;
		cin>>p->conte;
		cout<<"�������µ��ײͼ۸�"<<endl;
		cin>>p->price; 			
		}
		p=p->next;
	}
	if(flag==1) cout<<"û�д˶�����������!"<<endl;
 } 

void  Deletepackage(MenuList &L1)  //ɾ���ײ� 
{
		LNode *p;
		p=L1;
		T_ElemType e; 
		PrintfOrder(L1);
		int flag=1;
		cout<<"��������Ҫ�޸ĵ��ײ͵ı�ţ�";
		cin>>e.Tnum;
		while(p!=NULL)
		{
			if(p->num==e.Tnum)
			{	
				cout<<"������Ҫ�޸ĵ�״̬������Ԥ��Ϊ 1������Ԥ��Ϊ 0��"<<endl;
				int i;
				cin>>i;
				flag=0;
				if(i==p->cond)
				cout<<"������ǰ״̬�����޸�״̬��ͬ��������ģ�";
				
				else 
				{
					p->cond=i;  cout<<"�ײ���Ϣ�޸���ɣ�"; 
				}
			}
			p=p->next;
	}
	if(flag==1) cout<<"û�д˶����������ԣ�"<<endl;
	
}

Status AddOrder(SqList &L,SqQueue &Q)//��ָ��λ����Ӷ��� 
{
	ElemType e;	
	int i;
	cout<<"��ǰ���һ��Ϊ��"<<L.length<<endl<<"����������������:"	;
	cin>>i;	
	if(i>0&&i<=L.length) 
	{ 
		string s;
	    time_t time_T;
	    time_T = time(NULL);
	
	    struct tm *tmTime;
	    // tm�����ʽ��ʱ��
	    tmTime = localtime(&time_T);
	    const char *format="%Y-%m-%d%H:%M:%S"; const char *format1="%Y%m%d%H%M%S";
	    char strTime[100]; char strTime1[100];
	    
	    strftime(strTime1, sizeof(strTime1), format1, tmTime);
	    strftime(strTime, sizeof(strTime), format, tmTime);
		e.M.o_ID=strTime1; 
		e.M.o_time=strTime;
	
		int addressnum;
		
		string o_num_input;
		cout<<"�������ײͱ�ţ�"; cin>>o_num_input;

		e.M.o_num=o_num_input;cout<<endl; 
		cout<<"�����붩��������"; cin>>e.M.o_nums;cout<<endl;
		cout<<"�����붩���˵�������";cin>>e.M.p_name; cout<<endl;
		cout<<"�����붩���˵ĵ绰��";cin>>e.M.p_phone;
		
		cout<<"1\t������У��"<<endl;cout<<"2\t������У��"<<endl;
		cout<<"3\t����С��"<<endl;cout<<"4\t����Ѻ�"<<endl;
		cout<<"5\t��ͨ��԰"<<endl;cout<<"6\t���ֿ���"<<endl;
		cout<<"7\t���Ĳ���"<<endl;cout<<"8\t�����԰"<<endl;
		cout<<"9\t��ƽ����"<<endl;cout<<"10\t�����"<<endl;
		//�����ַ�ÿͻ�ѡ�� 
		
		cout<<"�����붩�͵�ַ��";cin>>addressnum;
		e.M.o_cond=1;//Ĭ��Ϊ�ѽ��գ�δ���� 
	
				if(addressnum==1) e.M.address="������У��";
				if(addressnum==2) e.M.address="������У��";
				if(addressnum==3) e.M.address="����С��";
				if(addressnum==4) e.M.address="����Ѻ�";
				if(addressnum==5) e.M.address="��ͨ��԰";
				if(addressnum==6) e.M.address="���ֿ���";
				if(addressnum==7) e.M.address="���Ĳ���";
				if(addressnum==8) e.M.address="�����԰";
				if(addressnum==9) e.M.address="��ƽ����";
				if(addressnum==10) e.M.address="�����";
				
	ListInsert(L,i,e);
	
	while(Q.front!=Q.rear)	DeQueue(Q,e);
	
	for(int i=0;i<L.length;i++) EnQueue(Q,L.elem[i]);
	}
	else cout<<"û�иÿ�λ�������ԣ�"<<endl;
//����ɶ����޸ĺ����¶������ 
}

Status DeleteOrder(SqList &L,SqQueue &Q)
{
	string o_ID;
	PrintAllList(L);//��ʾ���ж�������ѡ��
	 
	cout<<"����������ɾ���Ķ��������ݶ�����ţ�:";
	cin>>o_ID;
	
	if(ListDelete(L,Search_o_ID(L,o_ID))==OK) cout<<"ɾ���ɹ�"<<endl;
	else cout<<"ɾ��ʧ��"<<endl;
	
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
	
	PrintAllList(L);//��ʾ���ж�������ѡ��
	 
	cout<<"���������޸ĵĶ��������ݶ�����Ŷ�λ��:";
	cin>>o_ID;
	
	if(i=Search_o_ID(L,o_ID))
	{	
		cout<<"��ѡ�������޸ĵ���Ŀ"<<endl;
		cout<<"1\t�������\t"
			<<"2\t�ײͱ��"<<endl
			<<"3\t�ײ�����\t"
			<<"4\t����������"<<endl
			<<"5\t�����˵绰\t"
			<<"6\t���͵�ַ"<<endl
			<<"7\t�µ�ʱ��\t"
			<<"8\t״̬"<<endl;
		cin>>o_change_choice;
		switch(o_change_choice)
		{
			case 1:{
					cout<<"������14λ���:";
					cin>>L.elem[i].M.o_ID;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}
			
			case 2:{
					cout<<"�������ײͱ�ţ�4λ��MXXX��XXXΪ�������֣�:";
					cin>>L.elem[i].M.o_num;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}	
			
			case 3:{
					cout<<"�������ײ�����:";
					cin>>L.elem[i].M.o_nums;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}
			
			case 4:{
					cout<<"�����붩��������:";
					cin>>L.elem[i].M.p_name;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}
			
			case 5:{
					cout<<"�����붩���˵绰:";
					cin>>L.elem[i].M.p_phone;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}
			
			case 6:{ 							int addressnum;
												cout<<"1\t������У��"<<endl;cout<<"2\t������У��"<<endl;
												cout<<"3\t����С��"<<endl;cout<<"4\t����Ѻ�"<<endl;
												cout<<"5\t��ͨ��԰"<<endl;cout<<"6\t���ֿ���"<<endl;
												cout<<"7\t���Ĳ���"<<endl;cout<<"8\t�����԰"<<endl;
												cout<<"9\t��ƽ����"<<endl;cout<<"10\t�����"<<endl;
												//�����ַ�ÿͻ�ѡ�� 
												
												cout<<"���������͵�ַ:";cin>>addressnum;
												L.elem[i].M.o_cond=1;//Ĭ��Ϊ�ѽ��գ�δ���� 
									
												if(addressnum==1) L.elem[i].M.address="������У��";
												if(addressnum==2) L.elem[i].M.address="������У��";
												if(addressnum==3) L.elem[i].M.address="����С��";
												if(addressnum==4) L.elem[i].M.address="����Ѻ�";
												if(addressnum==5) L.elem[i].M.address="��ͨ��԰";
												if(addressnum==6) L.elem[i].M.address="���ֿ���";
												if(addressnum==7) L.elem[i].M.address="���Ĳ���";
												if(addressnum==8) L.elem[i].M.address="�����԰";
												if(addressnum==9) L.elem[i].M.address="��ƽ����";
												if(addressnum==10) L.elem[i].M.address="�����";
			cout<<"�޸ĳɹ�"<<endl;								
	
				break;
			}
			
			case 7:{
					cout<<"�������µ�ʱ��:";
					cin>>L.elem[i].M.o_time;
					cout<<"�޸ĳɹ�"<<endl;					
				break;
			}
			
			case 8:{
					cout<<"�����붩��״̬��1/0��:";
					cin>>L.elem[i].M.o_cond;
					cout<<"�޸ĳɹ�"<<endl; 
				break;
			}
			default:cout<<"�������������"<<endl;
																
		}
	}
} 


