#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,b,h[100001],cnt;
ll l=1,r=1e9,mid;
int main()
{
	cin>>n>>a>>b;
	a-=b;
	for (int i=0;i<n;++i) cin>>h[i];
	while (l!=r)
	{
		mid=(l+r)>>1;
		ll ans=0;
		for (int i=0;i<n;++i)
		{
			cnt=b*mid;
			if (cnt<h[i]) ans+=(h[i]-cnt-1)/a+1;
		}
		if (ans<=mid) r=mid;
		else l=mid+1;
	}
	cout<<l;
    return 0;
}