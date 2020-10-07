#include <iostream>
#include "LinkList.cpp"

using namespace std;
void ReversePrint(LinkList L){
	if(L->next!=NULL)
		ReversePrint(L->next);
	if(L!=NULL){
		cout<<L->data<<" ";
	}
}

int main(){
	LinkList L;
	L=List_HeadInsert(L);
	Print(L);
	ReversePrint(L->next);
}
