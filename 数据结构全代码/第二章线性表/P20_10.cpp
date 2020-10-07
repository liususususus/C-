#include <iostream>

using namespace std;

void find_mid(int a[],int b[],int m,int n,int &x){
	int index1=0,index2=0,k=0;
	while(k!=(m+n)/2-1){
		if(a[index1]<=b[index2]) index1++;
		else if(a[index1]>b[index2]) index2++;
		k++; 
	}
	if(a[index1]<=b[index2]){
		x=a[index1];
	} else {
		x=b[index2];
	}
}

int M_Search(int A[],int B[],int n) {
	int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
	while (s1!=d1 ||s2!=d2){
		m1=(s1+d1)/2;
		m2=(s2+d2)/2;
		cout<<"A[s1]:"<<A[s1]<<"B[s2]:"<<B[s2]<<endl; 
		cout<<"A[m1]:"<<A[m1]<<"B[m2]:"<<B[m2]<<endl; 
		cout<<"A[d1]:"<<A[d1]<<"B[d2]:"<<B[d2]<<endl<<endl;
		if(A[m1]==B[m2]) return A[m1];
		else if(A[m1]<B[m2]) {
			if((s1+d1)%2==0){
				s1=m1;
				d2=m2;	
			} else{
				s1=m1+1;
				d2=m2;
			}
			
		} else {
			if((s1+d1)%2==0){
				d1=m1;
				s2=m2;
			}
			else {
				s2=m2+1;
				d1=m1;
			}
		}
	}
	cout<<"A[s1]:"<<A[s1]<<"B[s2]:"<<B[s2]<<endl; 
		cout<<"A[m1]:"<<A[m1]<<"B[m2]:"<<B[m2]<<endl; 
		cout<<"A[d1]:"<<A[d1]<<"B[d2]:"<<B[d2]<<endl;  
	return A[s1]<B[s2]?A[s1]:B[s2];
}
int main(){
	int a[5]={11,13,15,17,19};
	int b[5]={2,4,6,8,20};
	int x;
	find_mid(a,b,5,5,x);
	cout<<x<<endl;
	x=M_Search(a,b,5);
	cout<<x<<endl;
	return 0;
}
