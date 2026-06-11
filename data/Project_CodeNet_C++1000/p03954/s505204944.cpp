#include<bits/stdc++.h>
#pragma GCC optimize(1,2,3,"Ofast","Os","inline")
#define rnt register int
using namespace std;
int a[2000011];
int n;
inline bool small(int i,int j,int k){return a[i]<=k&&a[j]<=k;}
inline bool big(int i,int j,int k){return a[i]>k&&a[j]>k;}
inline bool check(int x)
{
	for(rnt i=0;i<n-1;++i)
	{
		if(big(n+i,n+i+1,x)||big(n-i,n-i-1,x))return false;
		if(small(n+i,n+i+1,x)||small(n-i,n-i-1,x))return true;
	}
	return small(1,1,x);
}
int main()
{
	scanf("%d",&n);
	for(rnt i=1;i<=2*n-1;++i)scanf("%d",&a[i]);
	int l=1,r=2*n-1,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(check(mid)==true)r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}