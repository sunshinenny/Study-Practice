#ifndef _FUNCTION_H
#define _FUNCTION_H

//�˵����� 
void Menu(SqList &L,MenuList &L1,SqQueue &Q,AMGraph &G,int choice,int flag);

//�ļ���д����
int ReadFile(SqList &L,AMGraph &G,SqQueue &Q);//��ȡ������Ϣ  	
int ReadMenu(MenuList &L1);//��ȡ�ײ���Ϣ 
void OffWork(SqList &L,MenuList &L1);//�°�

//������� 
int PrintAllList(SqList L);//���ȫ���������� 
int PrintList(SqList L,int i);//���һ�Ŷ������� 

//˳�������� 
Status Node_InitList(MenuList &L1);//�½����� 
Status InitList(SqList &L);//�½�˳��� 
Status ListInsert(SqList &L,int i,ElemType e);//˳���Ĳ��� 
Status NodeInsert(MenuList&L,int i,T_ElemType e) ;//����Ĳ��� 
Status InitList(SqList &l);//˳����ʼ�� 
Status ListDelete(SqList &L,int i);//˳����ɾ�� 
void PrintList(SqList L);//���˳���

//��
Status InitQueue(SqQueue &Q);//���г�ʼ�� 
int QueueLength(SqQueue &Q);//���� 
Status EnQueue(SqQueue &Q,ElemType e);//���
Status FinishOrder(SqQueue &Q,ElemType &e,SqList &L,AMGraph &G);//���� ��ȫ���ܰ� 
ElemType GetHead(SqQueue Q);//ȡ���е�ͷ 
Status DeQueue(SqQueue &Q,ElemType e);//���� 

//���� 
int Search_p_phone(SqList L,string e);	
int Search_p_name(SqList L,string e);
int Search_o_ID(SqList L,string e);

//���Ͷ���
void SendOrder(SqQueue &Q,SqList &L,AMGraph &G);

//���·�� 
void SendOrder(AMGraph &G,int o_addressnum);//������
void Dijkstra(int Cost[][10],int n,int v0,int Distance[],int prev[]);
void PrintPrev(int prev[],int v0,int vn,int n);

//��������
void  Deletepackage(MenuList &L1) ; //ɾ���ײ� 
void  Changepackage(MenuList &L1);  //  �޸��ײ�
int Printf(MenuList L1);
void  Addpackage(MenuList &L1,SqList L) ;//  ����ײ�
void OrderManagement(SqList &L,SqQueue &Q,MenuList &L1); 
Status AddOrder(SqList &L,SqQueue &Q);//��ָ��λ����Ӷ��� 
Status DeleteOrder(SqList &L,SqQueue &Q);//ɾ������ 
Status ChangeOrder(SqList &L,SqQueue &Q);//�޸Ķ��� 


//ͳ��
void StatisticsOrder(SqList L,MenuList L1);
void StatisticsMonth(SqList &L,MenuList L1); 
void StatisticsDay(SqList L,MenuList L1);

#endif


