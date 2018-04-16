#include"Type.h" 
#include"Function.h"
//-------------------���·���㷨---------------------------
void SendOrder(AMGraph &G,int o_addressnum)//������
{
	int i,j;
	int Cost[10][10];// �����������Ķ�������
	
	char *Vertex[10]={"������У��","������У��","����С��","����Ѻ�","��ͨ��԰","���ֿ���","���Ĳ���","�����԰","��ƽ����","�����"};
 
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			Cost[i][j]=G.arcs[i][j];
		}// �������������ڽӾ���
	}
			
	int Distance[10];//�����õ����·������
	int prev[10];//�����õ����·��

	// �������ڽӾ��󡢶���������������±ꡢ�������
	Dijkstra(Cost,10,0,Distance,prev);//���� Dijkstra �㷨�������󶥵� V1 �������������·��

	i=o_addressnum;	
	cout<<"·��"<<endl<<endl;	
	PrintPrev(prev,0,i,10);//������·��ǰһ���¼����������±ꡢ������±ꡢ������

	cout <<"-->"<<Vertex[i]<<endl<<endl;
	cout<<"����\t"<<Distance[i]<<"m"<<endl<<endl<<"Ԥ����ʱ:"<<Distance[i]/500<<"����"<<endl<<endl;
} 

 
void Dijkstra(int Cost[][10],int n,int v0,int Distance[],int prev[])
{
	int s[10];//��ʼ��
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
	
	s[v0] =1;//��� v0
	//�ڵ�ǰ��δ�ҵ����·���Ķ����У�
	//Ѱ�Ҿ�����̾���Ķ���
	for(i=1;i<n;i++)
	{// ÿѭ��һ�Σ����һ�����·��
		mindis=MaxInt;
		u = v0;
		for (j=0;j<n;j++) // �������������Ķ���
		if(s[j]==0&&Distance[j]<mindis)
		{
			mindis=Distance [j];
			u=j;
		}//if ����������j ѭ������
		s[u] = 1;
		for(j=0;j<n;j++) // �޸ĵ���·�����У����ϣ�
		if(s[j]==0&&Cost[u][j]<MaxInt)
		{//�Ի�δ������·���Ķ���
		//���������Ķ��� ֱ�������ľ���
			dis=Distance[u] +Cost[u][j];
			//����µ�·�����̣����滻��ԭ·��
			if(Distance[j]>dis)
			{
				Distance[j] = dis;
				prev[j] = u;
			}
		}//if ����������j ѭ������
	}//i ѭ������
}//������·��
	

void PrintPrev(int prev[],int v0,int vn,int n)//��ʾ·���Ĵ��� 
{//������·��ǰһ���¼����������±ꡢ������±ꡢ������
	int tmp = vn;
	int i = 0;
	//��ʱ��·��
	int *tmpprv = new int[n];
	//��ʼ������
	char *Road[10]={"������У��","������У��","����С��","����Ѻ�","��ͨ��԰","���ֿ���","���Ĳ���","�����԰","��ƽ����","�����"};
	
	for(int ii=0;ii<n;ii++)
	tmpprv[ii] = 0;
	//��¼������±�
	tmpprv[0] = vn+1;
	//�м����ѭ����¼
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
	{//���·���������������
		if(tmpprv[i]!=0)
		{//�ų� 0 Ԫ��
			cout<<Road[tmpprv[i]-1];
			if(i)//�������һ���������
			cout <<"-->";
		}
	}
} 

