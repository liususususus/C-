#include<iostream>
#include"SqList.cpp"
using namespace std;

void Delete_ST(SqList &L,ElemType s,ElemType t){
	if (s >= t || L.length == 0)
	cout<<"�������ݲ������˳���Ϊ�գ�"<<endl;
	else {
		int k=0;
		for (int i = 0; i < L.length; i++) {
			if (L.elem[i] < s || L.elem[i] > t){
				L.elem[k] = L.elem[i];
				k++;
			}
		}
		L.length = k;
	} 
	
}
int main(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L,1,6-i);
	}
	PrintList(L);
	Delete_ST(L,1,4);
	PrintList(L);
	return 0;
}
