#include<iostream>
using namespace std;
#include <time.h>//ʱ�������ͷ�ļ� 
#include<stdlib.h>
#include<string>
#include<iomanip>//���������ʽ���� 
#include<fstream>//�ļ���д
using namespace std;

#define MAXSIZE 100
#define MaxInt 32767//��ʾ����ֵ 
#define MVNum 100//��󶥵���
#define OK 1
#define ERROR -1
#define OVERFLOW -2	

typedef char  VerTexType;//�������������Ϊ�ַ��� 
typedef float ArcType;//�ߵ�Ȩֵ����Ϊ����
typedef int Status; 
typedef int Status;

typedef struct
{
	VerTexType vexs[MVNum];//char���͵Ķ��� 
	ArcType arcs[MVNum][MVNum];//������֮���Ȩֵ 
	int  vexnum,arcnum;
} AMGraph;//ͼ�����·�� 

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
	string o_ID;//�������ID������ʱ�����ɣ� 
	string o_num;//�ײ͵� ��ţ�eg��M001�� 
	int o_nums;//�������� 
	string p_name;//���������� 
	string p_phone;//�����˵绰���� 
	string address;//��ַ 
	int  o_cond;//����״̬���ѽ��ܣ�������||1��0�� 
	
	//�µ�ʱ��
	string o_time; 
	string t_year;
	string t_month;
	string t_day; 
}message;//�����Ľṹ�� 


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
	string name;//�ײ����� 
	int t_nums=0;//�ײ�����-��ʼΪ0 
	int price;//�۸� 
	string year;//�� 
	string month;//�� 
} Statistics_month;//ͳ���¶��� 

