#include<iostream>
#include"SqList.cpp"
using namespace std; 

ElemType Minmum (SqList &L){
	if (Empty(L)){
		cout<<"顺序表为空！"<<endl;
		exit(0); 
	} else {
		ElemType min,d;
		int e = 0;
		for (int i = 1; i < L.length; i++) {
			if (L.elem[e] > L.elem[i]) {		
				e = i;
			}		
		}
		min = L.elem[e];
		L.elem[e] = L.elem[L.length-1];
		L.length--;
		cout<<"最小值为:"<<min<<endl; 
		return min;
	}
} 

int main(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 6 ; i++) {
		ListInsert(L,1,6-i);
	}
	PrintList(L);
	Minmum(L);
	PrintList(L);
	
	return 0;
}
