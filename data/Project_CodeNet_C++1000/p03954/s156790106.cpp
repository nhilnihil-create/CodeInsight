#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[2*N];
int b[2*N];

int check(int mid){
	for(int i=1;i<2*n;i++)
		if(a[i]>=mid) b[i]=1;
		else b[i]=0;
	for(int i=1;i<n;i++){	
		if(b[n-i]==b[n-i+1]) return b[n-i];
		if(b[n+i]==b[n+i-1]) return b[n+i];
	}
	return b[1];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<2*n;i++) scanf("%d",a+i);
	int l=1,r=2*n-1;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
