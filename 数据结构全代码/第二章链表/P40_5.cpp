#include <iostream>
#include "LinkList.cpp"

using namespace std;
LinkList ReverseL(LinkList L){
	LNode *p,*r;
	p=L->next;
	L->next=NULL;
	while(p){
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=r;
	}
	return L;
}

int main(){
	LinkList L;
	L=List_HeadInsert(L);
	Print(L);
	ReverseL(L);
	Print(L);
}
