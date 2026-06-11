#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define inf 0x3f3f3f3f3f3f3f
typedef long long ll;
using namespace std;
int k,n,x;
int a[2010];
int query(int l,int r)
{
	int ans=inf;
	if(l>=1)
	{
		for(int i=l;i<=r;i++)
		ans=min(ans,a[i]);
	}
	else
	{
		for(int i=1;i<=r;i++)
		 	ans=min(ans,a[i]);
		l=l+n;
		for(int i=l;i<=n;i++)
			ans=min(ans,a[i]);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll ans=inf,sum;
	for(k=0;k<=n-1;k++)
	{
		sum=0;
		for(int i=1;i<=n;i++)
		{
			sum+=query(i-k,i);
		}
		sum+=x*k;
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}