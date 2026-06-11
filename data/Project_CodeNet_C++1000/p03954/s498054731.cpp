#include <bits/stdc++.h>
using namespace std;

const long long INF=1012345678012345LL;

int main(){
	int n;
	scanf("%d",&n);
	int arr[2*n-1];
	for(int i=0;i<2*n-1;i++)scanf("%d",&arr[i]);
	int t[2*n-1];
	int l=1,r=2*n-1;
	while(l<r){
		int m=(l+r+1)/2;
		for(int i=0;i<2*n-1;i++)t[i]=(arr[i]>=m);
		int a=-1,cur=0;
		for(int x=1;x<n;x++){
			if(t[n-1+x]==t[n-1+(x-1)]&&t[n-1-x]==t[n-1-(x-1)]){
				if(t[n-1+x]==t[n-1-x])a=t[n-1+x];
				else{
					if(cur>=x)a=1;
					else a=0;
				}
				break;
			}else if(t[n-1+x]==t[n-1+(x-1)]){
				a=t[n-1+x];break;
			}else if(t[n-1-x]==t[n-1-(x-1)]){
				a=t[n-1-x];break;
			}
			cur+=t[n-1-x]+t[n-1+x];
		}
		if(a==-1){
			if(t[0]==0)a=0;
			else a=1;
		}
		if(a)l=m;
		else r=m-1;
	}
	printf("%d",l);
}
