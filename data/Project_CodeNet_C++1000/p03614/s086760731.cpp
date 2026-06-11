#include<cstdio>
#include<iostream>
const int M = 1000005;
int a[M];
using namespace std;
int main(){
	int n,j,i,k=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++){
		if(a[i]==i){
			int t=a[i];a[i]=a[i+1];a[i+1]=t;
			k++;
		} 
	} 
	cout<<k;
}