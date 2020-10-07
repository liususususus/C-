#include <iostream>
#include "LinkList.cpp"

using namespace std;
void DelMin(LinkList &L){
	if(L->next==NULL)	return;
	LNode *p=L->next;
	ElemType c=p->data;
	int k=1,j=1;
	p=p->next;
	while(p){
		j++;
		if(c>p->data){
			c=p->data;
			k=j;
		}
		p=p->next;
	}
	LNode *q=L->next;
	p=L;
	for(int i=1;i<k;i++){
		p=q;
		q=q->next;
	}
	p->next=q->next;
	delete q;
}
LinkList DelMin1(LinkList &L){
	LNode *pre=L,*p=pre->next;
	LNode *minpre=pre,*minp=p;
	while(p!=NULL){
		if(p->data<minp->data){
			minp=p;
			minpre=pre;
		}
		pre=p;
		p=p->next;
	} 
	minpre->next=minp->next;
	delete minp;
	return L;
}

int main(){
	LinkList L;
	L=List_HeadInsert(L);
	Print(L);
	DelMin1(L);
	Print(L);
}
