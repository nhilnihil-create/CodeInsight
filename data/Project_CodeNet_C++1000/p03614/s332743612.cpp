#include<cstdio>
#include<iostream>
using namespace std;
int a[100002],b[100002]={0};
int main(){
	int n;
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			b[i]=1;
		}
	}
	int sum=0,k=0,flag=0;
	for(i=1;i<=n+1;i++){
		if(b[i]==1){
			k++;
			flag=1;
		}else{
			if(flag==1){
				sum=sum+(k+1)/2;
				k=0;
				flag=0;
			}	
		}
	}
	cout<<sum<<endl;
	return 0;
}