#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	int k;
	int d[10]={};
	int in;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d",&in);
		d[in]=1;
	}
	int ans;
	for(ans=n;;ans++){
		int temp=ans,flag=0;
		while(temp>0){
			if(d[temp%10]){
				flag=1;
				break;
			}
			temp/=10;
		}
		if(!flag){
			cout<<ans<<endl;
			break;
		}
	}
	return 0;
}
