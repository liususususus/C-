#include<iostream>
#include"SqList.cpp"
using namespace std;

void DeleteRepeat(SqList &L) {
	int k = 1;
	for (int i = 1; i < L.length; i++) {
		if (L.elem[i] != L.elem[i-1]) {
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
	ListInsert(L,2,2);
	ListInsert(L,1,1);
	PrintList(L);
	DeleteRepeat(L);
	PrintList(L);
	return 0;
}
