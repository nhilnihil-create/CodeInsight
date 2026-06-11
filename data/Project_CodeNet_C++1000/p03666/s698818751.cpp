#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

ll n,a,b,l,r,F;

int main()
{
	cin>>n>>a>>b>>l>>r; n--;
	for(ll i=0;i<=n;i++)
	{
		ll L=a-i*r+(n-i)*l;
		ll R=a-i*l+(n-i)*r;
		if(b>=L&&b<=R) F=1;
	}
	if(F) puts("YES"); else puts("NO");
	return 0;
}