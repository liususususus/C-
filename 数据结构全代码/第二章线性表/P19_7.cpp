#include<iostream>
#include"SqList.cpp"
using namespace std;

SqList &Merge (SqList &L1, SqList &L2) {
	SqList L;
	InitList(L,L1.length+L2.length);
	int k = 0,index1 = 0,index2 = 0;
	for (int i = 0; i < L1.length + L2.length; i++) {
		if(index1 < L1.length && index2 < L2.length){
			if (L1.elem[index1] < L2.elem[index2]){
				L.elem[k++] = L1.elem[index1++];				
			} else {
				L.elem[k++] = L2.elem[index2++];				
			}
		}
		else if (index1 == L1.length && index2 < L2.length) {
			L.elem[k++] = L2.elem[index2++];	
		} else if (index2 == L2.length && index1 < L1.length) {
			L.elem[k++] = L1.elem[index1++];
		}
		
	}
	L.length = k;
	DestroyList(L1);
	DestroyList(L2);
	return L;
}

int main() {
	SqList L1,L2,L;
	InitList(L1);
	InitList(L2);
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L1,1,6-i);
	}
	PrintList(L1);
	
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L2,1,10-i);
	}
	PrintList(L2);
	L = Merge(L1,L2);
	PrintList(L);
	return 0;
} 
