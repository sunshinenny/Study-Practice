#include"Type.h" 
#include"Function.h"
//-------------------最短路径算法---------------------------
void SendOrder(AMGraph &G,int o_addressnum)//主函数
{
	int i,j;
	int Cost[10][10];// 给出有向网的顶点数组
	
	char *Vertex[10]={"华航东校区","华航西校区","金桥小区","阳光佳和","运通家园","格林郡府","华夏铂宫","锦绣家园","和平丽景","万向城"};
 
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			Cost[i][j]=G.arcs[i][j];
		}// 给出有向网的邻接矩阵
	}
			
	int Distance[10];//存放求得的最短路径长度
	int prev[10];//存放求得的最短路径

	// 参数：邻接矩阵、顶点数、出发点的下标、结果数组
	Dijkstra(Cost,10,0,Distance,prev);//调用 Dijkstra 算法函数，求顶点 V1 到其余各点的最短路径

	i=o_addressnum;	
	cout<<"路线"<<endl<<endl;	
	PrintPrev(prev,0,i,10);//参数：路径前一点记录、出发点的下标、到达点下标、顶点数

	cout <<"-->"<<Vertex[i]<<endl<<endl;
	cout<<"距离\t"<<Distance[i]<<"m"<<endl<<endl<<"预计用时:"<<Distance[i]/500<<"分钟"<<endl<<endl;
} 

 
void Dijkstra(int Cost[][10],int n,int v0,int Distance[],int prev[])
{
	int s[10];//初始化
	int mindis,dis;
	int i,j,u;	
	
	for(i=0;i<n;i++)
	{
		Distance[i]=Cost[v0][i];
		s[i]=0;
		if(Distance[i]==MaxInt)
		prev[i] = -1;
		else
		prev[i] = v0;
	} 
	
	Distance[v0] = 0;
	
	s[v0] =1;//标记 v0
	//在当前还未找到最短路径的顶点中，
	//寻找具有最短距离的顶点
	for(i=1;i<n;i++)
	{// 每循环一次，求得一个最短路径
		mindis=MaxInt;
		u = v0;
		for (j=0;j<n;j++) // 求离出发点最近的顶点
		if(s[j]==0&&Distance[j]<mindis)
		{
			mindis=Distance [j];
			u=j;
		}//if 语句体结束，j 循环结束
		s[u] = 1;
		for(j=0;j<n;j++) // 修改递增路径序列（集合）
		if(s[j]==0&&Cost[u][j]<MaxInt)
		{//对还未求得最短路径的顶点
		//求出由最近的顶点 直达各顶点的距离
			dis=Distance[u] +Cost[u][j];
			//如果新的路径更短，就替换掉原路径
			if(Distance[j]>dis)
			{
				Distance[j] = dis;
				prev[j] = u;
			}
		}//if 语句体结束，j 循环结束
	}//i 循环结束
}//输出最短路径
	

void PrintPrev(int prev[],int v0,int vn,int n)//显示路径的代码 
{//参数：路径前一点记录、出发点的下标、到达点下标、顶点数
	int tmp = vn;
	int i = 0;
	//临时存路径
	int *tmpprv = new int[n];
	//初始化数组
	char *Road[10]={"华航东校区","华航西校区","金桥小区","阳光佳和","运通家园","格林郡府","华夏铂宫","锦绣家园","和平丽景","万向城"};
	
	for(int ii=0;ii<n;ii++)
	tmpprv[ii] = 0;
	//记录到达点下标
	tmpprv[0] = vn+1;
	//中间点用循环记录
	for(int j=0;j<n;j++)
	{
		if(prev[tmp] != -1&&tmp != 0)
		{
			tmpprv[i] = prev[tmp]+1;
			tmp = prev[tmp];
			i++;
		} 
		else break;
	} 

	for(int i=n-1;i>=0;i--)
	{//输出路径，数组逆向输出
		if(tmpprv[i]!=0)
		{//排除 0 元素
			cout<<Road[tmpprv[i]-1];
			if(i)//不是最后一个输出符号
			cout <<"-->";
		}
	}
} 

