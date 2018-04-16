#ifndef _FUNCTION_H
#define _FUNCTION_H

//菜单函数 
void Menu(SqList &L,MenuList &L1,SqQueue &Q,AMGraph &G,int choice,int flag);

//文件读写函数
int ReadFile(SqList &L,AMGraph &G,SqQueue &Q);//读取订单信息  	
int ReadMenu(MenuList &L1);//读取套餐信息 
void OffWork(SqList &L,MenuList &L1);//下班

//输入输出 
int PrintAllList(SqList L);//输出全部订单内容 
int PrintList(SqList L,int i);//输出一排订单内容 

//顺序表和链表 
Status Node_InitList(MenuList &L1);//新建链表 
Status InitList(SqList &L);//新建顺序表 
Status ListInsert(SqList &L,int i,ElemType e);//顺序表的插入 
Status NodeInsert(MenuList&L,int i,T_ElemType e) ;//链表的插入 
Status InitList(SqList &l);//顺序表初始化 
Status ListDelete(SqList &L,int i);//顺序表的删除 
void PrintList(SqList L);//输出顺序表

//队
Status InitQueue(SqQueue &Q);//队列初始化 
int QueueLength(SqQueue &Q);//长度 
Status EnQueue(SqQueue &Q,ElemType e);//入队
Status FinishOrder(SqQueue &Q,ElemType &e,SqList &L,AMGraph &G);//出队 ·全功能版 
ElemType GetHead(SqQueue Q);//取队列的头 
Status DeQueue(SqQueue &Q,ElemType e);//出队 

//查找 
int Search_p_phone(SqList L,string e);	
int Search_p_name(SqList L,string e);
int Search_o_ID(SqList L,string e);

//派送订单
void SendOrder(SqQueue &Q,SqList &L,AMGraph &G);

//最短路径 
void SendOrder(AMGraph &G,int o_addressnum);//主函数
void Dijkstra(int Cost[][10],int n,int v0,int Distance[],int prev[]);
void PrintPrev(int prev[],int v0,int vn,int n);

//订单管理
void  Deletepackage(MenuList &L1) ; //删除套餐 
void  Changepackage(MenuList &L1);  //  修改套餐
int Printf(MenuList L1);
void  Addpackage(MenuList &L1,SqList L) ;//  添加套餐
void OrderManagement(SqList &L,SqQueue &Q,MenuList &L1); 
Status AddOrder(SqList &L,SqQueue &Q);//在指定位置添加订单 
Status DeleteOrder(SqList &L,SqQueue &Q);//删除订单 
Status ChangeOrder(SqList &L,SqQueue &Q);//修改订单 


//统计
void StatisticsOrder(SqList L,MenuList L1);
void StatisticsMonth(SqList &L,MenuList L1); 
void StatisticsDay(SqList L,MenuList L1);

#endif


