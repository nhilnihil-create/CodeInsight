#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

deque<ll> ans;

ll n;
bool bo[233];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();ll hh=0;
	while (n)
	{
		if (n&1) bo[++hh]=true,n=(n-1)>>1;
		else bo[++hh]=false,n--;
	}
	printf("%lld\n",hh<<1);
	for (int i=hh;i;i--) if (bo[i]) ans.push_back(hh-i+1);else ans.push_front(hh-i+1);
	for (ll i=0;i<hh;i++) printf("%lld ",ans[i]);
	for (ll i=1;i<=hh;i++) printf("%lld ",i);
	puts("");
	return 0;
}