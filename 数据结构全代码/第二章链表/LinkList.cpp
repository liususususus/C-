#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList; 

LinkList List_HeadInsert(LinkList &L){
	LNode *s;
	int x;
	L=new LNode;
	L->data=100;
	L->next=NULL;
	cin>>x;
	while(x!=99){
		s=new LNode;
		s->data=x;
		s->next=L->next;
		L->next=s;
		cin>>x;
	} 
	return L;
}

LNode *GetElem(LinkList L,int i){
	int j=1;
	LNode *p=L->next;
	if(i==0)	return L;
	if(i<1)	return NULL;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	return p;
}

LNode *LocateElem(LinkList L,ElemType e){
	LNode *p=L->next;
	while(p&&p->data!=e){
		p=p->next;
	}
	return p;
}

void Print(LinkList L){
	LNode *p=L->next;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
} 
