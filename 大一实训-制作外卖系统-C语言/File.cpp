#include"Type.h" 
#include"Function.h"
//-------------------有关所有的文件读写---------------------------
int  ReadMenu(MenuList &L1) 
{ //读取“套餐信息”，而不是订单信息 
	int i=0;
	ifstream  in("套餐信息.txt",ios::in);      //以读的方式打开文件
	if(!in)                                //打开失败
	{
		cout<<"套餐信息文件打开失败！"<<endl;
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
	 	ifstream  in("订单信息.txt",ios::in);      //以读的方式打开文件
		if(!in)                                //打开失败
		{
			cout<<"订单信息文件打开失败！"<<endl;
			return  ERROR;
		}
	  
	  ElemType e; 
	  
	  while(in>>L.elem[m].M.o_ID >>L.elem[m].M.o_num >>L.elem[m].M.o_nums
	  			>>L.elem[m].M.p_name>>L.elem[m].M.p_phone>>L.elem[m].M.address
				  >>L.elem[m].M.o_time>>L.elem[m].M.o_cond
				  	>>L.elem[m].M.t_year>>L.elem[m].M.t_month>>L.elem[m].M.t_day)  //读取文件中信息 
		{	 
			e=L.elem[m];
			L.length++;
			if(L.elem[m].M.o_cond==1)//如果订单状态为1（未派送） 
			EnQueue(Q,e);// 即入队
			m++;
		}
		in.close();   
	}

	cout<<endl;

	//读取地图信息； 
	{	ifstream  in("地图信息.txt",ios::in);//以读的方式打开文件
		if(!in)//判断打开成败 
		{
			cout<<"地图信息文件打开失败！"<<endl;
			return ERROR;
		}
		
		int i,j,k,v1,v2;
		G.vexnum=10,G.arcnum=30;//一共有30个点在邻接矩阵中需要改变 
		for(i=0;i<G.vexnum;++i)
		G.vexs[i]=i+1;//地点编号；//将10个顶点对应10个地点编号 //G.vexs[i]=i+1;  
		float dis[30];//定义数组存权值 
	
		for(i=0;i<G.vexnum;++i)
			for(j=0;j<G.vexnum;++j) 
			 G.arcs[i][j]=MaxInt;//先将邻接矩阵全部节点赋值为 MAXInt 
		for(i=0;i<G.vexnum;i++)		G.arcs[i][i]=0;	//将对角线上的值修改为0（到达不了自己）	 
			  
		int m=0;	 
		string Qaddress[30],Zaddress[30]; //Q是起点 Z是终点 
	
		while(in>>Qaddress[m]>>Zaddress[m]>>dis[m])//读取了地点文件 将两个地点之间距离赋值给他们的权值
		{
			if(Qaddress[m]=="华航东校区")	i=1;	if(Qaddress[m]=="华航西校区")	i=2;
			if(Qaddress[m]=="金桥小区")		i=3;	if(Qaddress[m]=="阳光佳和")		i=4;
			if(Qaddress[m]=="运通家园")		i=5;	if(Qaddress[m]=="格林郡府")		i=6;
			if(Qaddress[m]=="华夏铂宫")		i=7;	if(Qaddress[m]=="锦绣家园")		i=8;
			if(Qaddress[m]=="和平丽景")		i=9;	if(Qaddress[m]=="万向城")		i=10;
	
			if(Zaddress[m]=="华航东校区")	j=1;	if(Zaddress[m]=="华航西校区")	j=2;
			if(Zaddress[m]=="金桥小区")		j=3;	if(Zaddress[m]=="阳光佳和")		j=4;
			if(Zaddress[m]=="运通家园")		j=5;	if(Zaddress[m]=="格林郡府")		j=6;
			if(Zaddress[m]=="华夏铂宫")		j=7;	if(Zaddress[m]=="锦绣家园")		j=8;
			if(Zaddress[m]=="和平丽景")		j=9;	if(Zaddress[m]=="万向城")		j=10;
			
			--i,--j; //1-0
			G.arcs[i][j]=dis[m];//读取了地点文件 将两个地点之间距离赋值给他们的权值 
			m++;
				
	  	} //定义完了邻接矩阵
	
		in.close(); //关闭文件 
	}

	return OK;
} 

void OffWork(SqList &L,MenuList &L1)
{//下班 

	int i,j;int t=0;
	LNode *p;
	if(L.length<=0)
	{
		cout<<"写入文件错误！"<<endl;
		exit(0);
	}
//写入订单信息	
{
	ofstream out("订单信息.txt",ios::out);
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
	cout<<endl<<"订单信息写入成功！"<<endl;	
}
//写入套餐信息 
{
	ofstream out("套餐信息.txt",ios::out);
	if(!out)
	{
		cout<<"Open Error"<<endl;
		return ;
	}
	
	if(!out)
	{
		cout<<"写入文件错误！"<<endl;
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
	cout<<endl<<"套餐信息写入成功！"<<endl;
}
	exit(0); 
}



