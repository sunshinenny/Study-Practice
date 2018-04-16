#include"Type.h" 
#include"Function.h"

int main()
{
	SqList L;
    MenuList L1; SqQueue Q; 
	AMGraph G; 
	int flag=0;
	int choice;
	int i;
	
	if(InitList(L)==OK&&Node_InitList(L1)==OK&&InitQueue(Q)==OK )
	Menu(L,L1,Q,G,choice,flag);
}


