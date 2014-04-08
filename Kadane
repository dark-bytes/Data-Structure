//Kadane's algorithm

#include<iostream>
using namespace std;

int max(int[],int);

int main(){
	int a[200];
	int n,i;
	cout<<"Enter number of elements->";
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<max(a,n);
}

int max(int a[],int n){
	int max_so_far=0;
	int max_here=0;
	for(int i=0;i<n;i++){
		max_here+=a[i];
		if(max_here<0)
			max_here=0;
		if(max_here>max_so_far)
			max_so_far=max_here;
	}
	
	return max_so_far;
}
