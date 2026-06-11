#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+50;
int n,m;
int l,r;
int a[maxn];
bool check(int mid)
{
	for(int i=0;i<=n-2;i++)
	{
		if((a[n+i]>mid&&a[n+i+1]>mid)||(a[n-i]>mid&&a[n-i-1]>mid))
			return false;
		if((a[n+i]<=mid&&a[n+i+1]<=mid)||(a[n-i]<=mid&&a[n-i-1]<=mid))
			return true;
	}
	if(a[1]<=mid)
		return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	m=2*n-1;
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	l=0,r=m+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	cout<<r<<endl;
	return 0;
}