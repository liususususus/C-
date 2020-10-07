#include<iostream>
#include"SqList.cpp"
using namespace std;

bool Find(SqList &L, int x,int left,int right) {
	cout<<"left:"<<left<<"right:"<<right<<endl;
	
	if (x == L.elem[(left+right)/2] && (left+right)/2 != L.length-1){
		int index = L.elem[(left+right)/2];
		L.elem[(left+right)/2]=L.elem[(left+right)/2+1];
		L.elem[(left+right)/2+1]=index;
		return true;
	} 
	if (left == right && x != L.elem[(left+right)/2]) {
		if(x>L.elem[(left+right)/2])
			ListInsert(L,left+2,x);
		else
			ListInsert(L,left+1,x);
		return false;
	}
	else if (x < L.elem[(left+right)/2]) {
		Find(L,x,left,(left+right)/2);
	} else if (x > L.elem[(left+right)/2]) {
		Find(L,x,(left+right)/2+1,right);
	}
	
}

int main(){
	SqList L;
	InitList(L);
	for (int i = 0; i < 10 ; i++) {
		ListInsert(L,1,10-i);
	}
	ListInsert(L,11,15);
	PrintList(L);
	Find(L,13,0,L.length-1);
	PrintList(L);
	return 0;
}
