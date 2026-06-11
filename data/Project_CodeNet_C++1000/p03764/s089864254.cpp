
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e5;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    1e9+7;
ll n,m;
ll go(ll x)
{
	ll ans=0;
	for(int i=1;i<=x;i++)
	{
		ll a;
		cin>>a;
		(ans+=(2*i-x-1)*a)%=mod;
	}
	return ans;
}
int main()
{  fast
cin>>n>>m;
ll x=go(n)%mod;
ll y=go(m)%mod;
cout<<x*y%mod;
}
