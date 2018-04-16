#include"Type.h" 
#include"Function.h"
//-------------------�й����е��ļ���д---------------------------
int  ReadMenu(MenuList &L1) 
{ //��ȡ���ײ���Ϣ���������Ƕ�����Ϣ 
	int i=0;
	ifstream  in("�ײ���Ϣ.txt",ios::in);      //�Զ��ķ�ʽ���ļ�
	if(!in)                                //��ʧ��
	{
		cout<<"�ײ���Ϣ�ļ���ʧ�ܣ�"<<endl;
		return ERROR;
	}
	T_ElemType e;
	while(in>>e.Tnum>>e.Tname>>e.Tconte>>e.Tprice>>e.Tcond)
	{
		 NodeInsert(L1,i,e);
		 i++;
	}
	in.close();
	
	return OK;
}

int ReadFile(SqList &L,AMGraph &G,SqQueue &Q)
{
  int m=0;
  
	{ 
	 	ifstream  in("������Ϣ.txt",ios::in);      //�Զ��ķ�ʽ���ļ�
		if(!in)                                //��ʧ��
		{
			cout<<"������Ϣ�ļ���ʧ�ܣ�"<<endl;
			return  ERROR;
		}
	  
	  ElemType e; 
	  
	  while(in>>L.elem[m].M.o_ID >>L.elem[m].M.o_num >>L.elem[m].M.o_nums
	  			>>L.elem[m].M.p_name>>L.elem[m].M.p_phone>>L.elem[m].M.address
				  >>L.elem[m].M.o_time>>L.elem[m].M.o_cond
				  	>>L.elem[m].M.t_year>>L.elem[m].M.t_month>>L.elem[m].M.t_day)  //��ȡ�ļ�����Ϣ 
		{	 
			e=L.elem[m];
			L.length++;
			if(L.elem[m].M.o_cond==1)//�������״̬Ϊ1��δ���ͣ� 
			EnQueue(Q,e);// �����
			m++;
		}
		in.close();   
	}

	cout<<endl;

	//��ȡ��ͼ��Ϣ�� 
	{	ifstream  in("��ͼ��Ϣ.txt",ios::in);//�Զ��ķ�ʽ���ļ�
		if(!in)//�жϴ򿪳ɰ� 
		{
			cout<<"��ͼ��Ϣ�ļ���ʧ�ܣ�"<<endl;
			return ERROR;
		}
		
		int i,j,k,v1,v2;
		G.vexnum=10,G.arcnum=30;//һ����30�������ڽӾ�������Ҫ�ı� 
		for(i=0;i<G.vexnum;++i)
		G.vexs[i]=i+1;//�ص��ţ�//��10�������Ӧ10���ص��� //G.vexs[i]=i+1;  
		float dis[30];//���������Ȩֵ 
	
		for(i=0;i<G.vexnum;++i)
			for(j=0;j<G.vexnum;++j) 
			 G.arcs[i][j]=MaxInt;//�Ƚ��ڽӾ���ȫ���ڵ㸳ֵΪ MAXInt 
		for(i=0;i<G.vexnum;i++)		G.arcs[i][i]=0;	//���Խ����ϵ�ֵ�޸�Ϊ0�����ﲻ���Լ���	 
			  
		int m=0;	 
		string Qaddress[30],Zaddress[30]; //Q����� Z���յ� 
	
		while(in>>Qaddress[m]>>Zaddress[m]>>dis[m])//��ȡ�˵ص��ļ� �������ص�֮����븳ֵ�����ǵ�Ȩֵ
		{
			if(Qaddress[m]=="������У��")	i=1;	if(Qaddress[m]=="������У��")	i=2;
			if(Qaddress[m]=="����С��")		i=3;	if(Qaddress[m]=="����Ѻ�")		i=4;
			if(Qaddress[m]=="��ͨ��԰")		i=5;	if(Qaddress[m]=="���ֿ���")		i=6;
			if(Qaddress[m]=="���Ĳ���")		i=7;	if(Qaddress[m]=="�����԰")		i=8;
			if(Qaddress[m]=="��ƽ����")		i=9;	if(Qaddress[m]=="�����")		i=10;
	
			if(Zaddress[m]=="������У��")	j=1;	if(Zaddress[m]=="������У��")	j=2;
			if(Zaddress[m]=="����С��")		j=3;	if(Zaddress[m]=="����Ѻ�")		j=4;
			if(Zaddress[m]=="��ͨ��԰")		j=5;	if(Zaddress[m]=="���ֿ���")		j=6;
			if(Zaddress[m]=="���Ĳ���")		j=7;	if(Zaddress[m]=="�����԰")		j=8;
			if(Zaddress[m]=="��ƽ����")		j=9;	if(Zaddress[m]=="�����")		j=10;
			
			--i,--j; //1-0
			G.arcs[i][j]=dis[m];//��ȡ�˵ص��ļ� �������ص�֮����븳ֵ�����ǵ�Ȩֵ 
			m++;
				
	  	} //���������ڽӾ���
	
		in.close(); //�ر��ļ� 
	}

	return OK;
} 

void OffWork(SqList &L,MenuList &L1)
{//�°� 

	int i,j;int t=0;
	LNode *p;
	if(L.length<=0)
	{
		cout<<"д���ļ�����"<<endl;
		exit(0);
	}
//д�붩����Ϣ	
{
	ofstream out("������Ϣ.txt",ios::out);
	for(i=0;i<L.length;i++)
	{
		out<<L.elem[i].M.o_ID<<"\t"
			<<L.elem[i].M.o_num<<"\t"
			<<L.elem[i].M.o_nums<<"\t"
			<<L.elem[i].M.p_name<<"\t"
			<<L.elem[i].M.p_phone<<"\t"
			<<L.elem[i].M.address<<"\t"
			<<L.elem[i].M.o_time<<"\t"
			<<L.elem[i].M.o_cond<<"\t"
			<<L.elem[i].M.t_year<<"\t"
			<<L.elem[i].M.t_month<<"\t"
			<<L.elem[i].M.t_day<<"\t"
			<<endl;
	}
	out.close();
	cout<<endl<<"������Ϣд��ɹ���"<<endl;	
}
//д���ײ���Ϣ 
{
	ofstream out("�ײ���Ϣ.txt",ios::out);
	if(!out)
	{
		cout<<"Open Error"<<endl;
		return ;
	}
	
	if(!out)
	{
		cout<<"д���ļ�����"<<endl;
		return ;
	}
	p=L1->next;

	while(p)
	{
		out<<p->num
			<<"\t"<<p->name
			<<"\t"<<p->conte
			<<"\t"<<p->price
			<<"\t"<<p->cond
			<<endl;
			p=p->next;
	}
	out.close();
	cout<<endl<<"�ײ���Ϣд��ɹ���"<<endl;
}
	exit(0); 
}



