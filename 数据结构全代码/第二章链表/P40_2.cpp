#include <iostream>
#include "LinkList.cpp"

using namespace std;

void Delete_X(LinkList &L,int x){
	LNode *p=L->next,*q=L;
	while(p){
		if(p->data==x){
			q->next=p->next;
			delete p;
			p=q->next;
		} else {
			q=p;
			p=p->next;
		}
	}
}

int main(){
	LinkList L;
	L=List_HeadInsert(L);
	
	Print(L);
	Delete_X(L,5);
	Print(L);
	return 0;
}
