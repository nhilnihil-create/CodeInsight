#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[500001],ans;
int big(int l,int r,int x){
	return a[l]>x&&a[r]>x;
}
int small(int l,int r,int x){
	return a[l]<=x&&a[r]<=x;
}
int pd(int x){
	int i;
	for(i=0;i<n-1;i++){
		if(big(n+i,n+i+1,x)||big(n-i,n-i-1,x))return 0;
		if(small(n+i,n+i+1,x)||small(n-i,n-i-1,x))return 1;
	}
	return small(1,1,x);
}
int main(){
	int i,j,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n*2-1;i++)scanf("%d",&a[i]);
	l=1;r=n*2-1;ans=n*2-1;
	while(l<=r){
		mid=(l+r)/2;
		if(pd(mid))ans=mid,r=mid-1;
		 else l=mid+1;
	}
	printf("%d",ans);
}