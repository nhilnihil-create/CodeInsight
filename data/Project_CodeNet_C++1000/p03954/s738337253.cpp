#include<bits/stdc++.h>
using namespace std;
int a[400005],n;
int small(int i,int k)
{
	return a[i+1]<=k&&a[i]<=k;//  
}
int big(int i,int k)
{
	return a[i+1]>k&&a[i]>k;
}
int check(int k)
{
	for(int i=0;i<=n-1;i++)
	{
		if(small(n+i,k)==1||small(n-i-1,k)==1)
		{
			return 1;
		}
		if(big(n+i,k)==1||big(n-i-1,k)==1)
		{
			return 0;
		}
	}
	if(a[1]<=k)
	{
		return 1;
	}else
	{
		return 0;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	int l=1,r=2*n-1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)==1)
		{
			r=mid;
		}else
		{
			l=mid+1;
		}
	}
	cout<<r;
	return 0;
}