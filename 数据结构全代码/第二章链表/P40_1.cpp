#include <iostream>
#include "LinkList.cpp"

using namespace std;

void Delete_X3(LinkList &L,int x){
	LNode *p,*q;
	if(!L)	return;
	if(L->data==x){
		p=L;
		L=L->next;
		delete p;
		Delete_X3(L,x);
	} else {
		Delete_X3(L,x);
	}
}

int main(){
	LinkList L;
	L=List_HeadInsert(L);
	
	Print(L);
	Delete_X3(L,5);
	Print(L);
	return 0;
}
