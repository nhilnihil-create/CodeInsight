#include<iostream>
#include<cmath>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include<vector>
#define MAXN 100005
using namespace std;
int a[2*MAXN],n;
bool check(int mid)
{
	for(int i=0;i<n-1;i++)
	{
		if((a[n-i]>mid&&a[n-i-1]>mid)||(a[n+i]>mid&&a[n+i+1]>mid))
			return false;
		if((a[n-i]<=mid&&a[n-i-1]<=mid)||(a[n+i]<=mid&&a[n+i+1]<=mid))
			return true;
	}
	return a[1]<=mid;
}
int ef(int l,int r)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
		scanf("%d",&a[i]);
	printf("%d",ef(1,2*n-1));
    return 0;
}
