#include<iostream>
#include<stack>
using namespace std;

typedef struct TNode{
	char data;
	struct TNode *lchild,*rchild;
}TNode,*Tree;

void visit(Tree T){
	if(T!=NULL){
		cout<<T->data<<" ";
	}
}

void PreOrder(Tree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

void InOrder2(Tree T){
	stack<Tree> S;
	Tree p=T;
	while(p||!S.empty()){
		if(p){
			S.push(p);
			p=p->lchild;
		}
		else {
			p=S.top();visit(p);
			S.pop();
		}
	}
}

void PreOrder2(Tree T){
	stack<Tree> S;
	Tree p=T;
	while(p||!S.empty()){
		if(p){
			visit(p);S.push(p);
			p=p->lchild;
		}
		else {
			p=S.top();
			S.pop();
		}
	}
}

void PostOrder2(Tree T){
	stack<Tree> S;
	Tree p=T,r=NULL;
	while(p||!S.empty()){
		if(p){
			S.push(p);
			p=p->lchild;
		}
		else {
			p=S.top();
			if(p->rchild&&r!=p->rchild){
				p=p->rchild;
				S.push(p);
				p=p->rchild;
			}
			else {
				p=S.top();
				visit(p);
				S.pop();
				r=p;
				p=NULL;
			}
		}
	}
} 


int main(){
	Tree T;
	return 0;
}
