#include<iostream>
#include"SqList.cpp"
using namespace std;

void Reverse(SqList &L) {
	ElemType index;
	for (int i = 0; i < L.length/2; i++){
		index = L.elem[i];
		L.elem[i] = L.elem[L.length-i-1];
		L.elem[L.length-i-1] = index;
	}
}
int main(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L,1,6-i);
	}
	PrintList(L);
	Reverse(L);
	PrintList(L);
	return 0;
}
