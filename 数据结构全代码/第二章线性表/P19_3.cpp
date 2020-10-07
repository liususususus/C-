#include<iostream>
#include"SqList.cpp"
using namespace std;

void Delete_X(SqList &L,ElemType x){
	int k=0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] != x){
			L.elem[k] = L.elem[i];
			k++;
		}
	}
	L.length = k;
}
int main(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L,1,6-i);
	}
	ListInsert(L,1,5);
	PrintList(L);
	Delete_X(L,5);
	PrintList(L);
	return 0;
}
