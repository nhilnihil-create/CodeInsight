#include<bits/stdc++.h>
using namespace std;
int n,a,b,h[100010];
bool check(int x)
{
	int res=0;
	for (int i=0;i<n;i++)
	{
		if (1LL*x*b>=1LL*h[i])
		{
			continue;
		}
		res+=(h[i]-x*b+a-1)/a;
		if (res>x)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	a-=b;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&h[i]);
	}
	int l=1,r=1e9,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid))
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<l<<endl;
	return 0;
}
