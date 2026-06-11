#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[100005];
int main(){
int n;
cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t;
	int sum=0;
	for(int i=1;i<=n;i++){
			if(a[i]==i){
				sum++;
						t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		
			}
	}
	printf("%d",sum);
}