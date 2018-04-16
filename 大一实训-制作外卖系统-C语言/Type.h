#include<iostream>
using namespace std;
#include <time.h>//时间操作的头文件 
#include<stdlib.h>
#include<string>
#include<iomanip>//输入输出格式控制 
#include<fstream>//文件读写
using namespace std;

#define MAXSIZE 100
#define MaxInt 32767//表示极大值 
#define MVNum 100//最大顶点数
#define OK 1
#define ERROR -1
#define OVERFLOW -2	

typedef char  VerTexType;//顶点的数据类型为字符型 
typedef float ArcType;//边的权值类型为整型
typedef int Status; 
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum];//char类型的定点 
	ArcType arcs[MVNum][MVNum];//两顶点之间的权值 
	int  vexnum,arcnum;
} AMGraph;//图，最短路径 

typedef struct
{
	string Tnum;
    string Tname;
	string Tconte;
	int Tprice;
	int num_price;
	int Tcond;
}T_ElemType; 

typedef struct LNode
{
	string num;
    string name; 
	string conte;
	int price;
	int num_price;
	int cond;
	struct LNode *next;
}LNode,*MenuList;

typedef struct
{
	string o_ID;//订单编号ID（根据时间生成） 
	string o_num;//套餐的 编号（eg：M001） 
	int o_nums;//订单数量 
	string p_name;//订单人姓名 
	string p_phone;//订单人电话号码 
	string address;//地址 
	int  o_cond;//订单状态（已接受，已派送||1，0） 
	
	//下单时间
	string o_time; 
	string t_year;
	string t_month;
	string t_day; 
}message;//订单的结构体 


typedef struct
{
	message M;
}ElemType; 

typedef struct
{
	ElemType *elem;
	int length;	
}SqList;

typedef struct
{
	ElemType *elem;
	int front;
	int rear;
}SqQueue;

typedef struct
{
	string name;//套餐名字 
	int t_nums=0;//套餐数量-初始为0 
	int price;//价格 
	string year;//年 
	string month;//月 
} Statistics_month;//统计月订单 

