#include<iostream>
#include<process.h>
using namespace std;

const int LIST_INIT_SIZE = 100;
const int LISTINCREMENT = 10;

typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
	int listsize;
	int incrementsize;
}SqList;

void InitList (SqList &L, int maxsize = LIST_INIT_SIZE, int incrementsize=LISTINCREMENT) {
	L.elem = new ElemType[maxsize];
	L.length = 0;
	L.listsize = 0;
	L.incrementsize = incrementsize; 
} 

int LocateElem (SqList &L, ElemType e) {
	int i = 1;
	ElemType *p = L.elem;
	while (i <= L.length && *(p+i-1) != e) {
		i++;
	}
	if (i <= L.length) {
		return i;
	}	else{
		return 0;
	}
}

void ErrorMessage (char *s) {
	cout << s << endl;
	exit(1);
}
void increment (SqList &L) {
	ElemType *a = new ElemType[L.listsize+L.incrementsize];
	for (int i = 0; i<L.length; i ++)	{
		a[i] = L.elem[i];
	}
	delete [] L.elem;
	L.listsize = L.listsize + L.incrementsize; 
}
void ListInsert (SqList &L, int i, ElemType e) {
	if (i < 1 || i > L.length+1)	ErrorMessage("i值不合法"); 
	if (L.length >= L.listsize) increment(L);
	ElemType *q = L.elem+i-1;
	ElemType *p = &(L.elem[L.length-1]);
	for ( ; p >= q ; p--) {
		*(p+1)	= *p;
	} 
	*q = e;
	L.length++;
}
bool Empty(SqList L){
	if(L.length==0)
	return true;
	else
	return false;
}
void ListDelete (SqList &L, int i, ElemType &e){
	if (i < 1 || i > L.length)	ErrorMessage("i值不合法");
	ElemType *q = L.elem+i-1;
	e = *q;
	for (ElemType *p = q; p <= L.elem+L.length-1; p++) {
		*p = *(p+1);
	}
	L.length--;
}

void DestroyList (SqList &L) {
	delete[] L.elem;
	L.length = 0;
	L.listsize = 0;
} 

void PrintList (SqList L){
	cout << "数组为：";
	if (L.length == 0) {
		ErrorMessage("数组为空！");
	} else{
		for (int i = 0; i < L.length; i++) {
			cout<<L.elem[i]<<" ";
		}
		cout << "  长度为：" <<L.length<<endl; 
	}
}


