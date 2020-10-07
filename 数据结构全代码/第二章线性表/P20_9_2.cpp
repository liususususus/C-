#include <iostream>

using namespace std;

void find(int A[],int x,int left,int right){
	int n=right;
	int mid=0; 
	while(left<=right){
		mid = (right+left)/2;
		cout<<"left:"<<left<<"right:"<<right<<endl;
		if(x==A[mid]) break;
		else if (x<A[mid])	right=mid-1;
		else if (x>A[mid])  left=mid+1;
 	}
 	if(A[mid]==x&&mid!=n-1){
 		int index=A[mid];
 		A[mid]=A[mid+1];
 		A[mid+1]=index;
	 }
	if(left>right){
		for(int i=n-1;i>right;i--)	A[i+1]=A[i];
		A[right+1]=x;
	}
}
int main(){
	int k=0;
	int A[20];
	for(int i=1;i<10;i++){
		A[k++]=2*i;
	}
	for(int i=0;i<k;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	find(A,15,0,9);
	for(int i=0;i<k+1;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return 0;
}
