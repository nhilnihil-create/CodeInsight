#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define INF 2e9
#define mod 1000000007
#define eps 1e-6
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
void read(ll &x)
{
	scanf("%lld",&x);
}
void read(ll &x, ll &y)
{
	scanf("%lld%lld",&x,&y);
}
void read(ll &x, ll &y, ll &z)
{
	scanf("%lld%lld%lld",&x,&y,&z);
}
void print(ll x)
{
	printf("%lld ",x);
}
void println(ll x)
{
	printf("%lld\n",x);
}
const ll N=100100;
ll n,m,a,b,cnt[N],ans,f[2*N],rf[2*N];
ll bin(ll a, ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)
			(ans*=a)%=mod;
		(a*=a)%=mod;
		n/=2;
	}
	return ans;
}
ll c(ll n, ll k)
{
	if(k>n||k<0)
		return 0;
	return f[n]*rf[k]%mod*rf[n-k]%mod;
}
ll calc(ll n, ll m)
{
	return c(n+m-2,m-1);
}
int main()
{
	cin>>n>>m>>a>>b;
	f[0]=1;
	for(ll i=1;i<=n+m;i++)
		f[i]=f[i-1]*i%mod;
	rf[n+m]=bin(f[n+m],mod-2);
	for(ll i=n+m-1;i>=0;i--)
		rf[i]=rf[i+1]*(i+1)%mod;
	for(ll i=b+1;i<=m;i++)
		cnt[i]=calc(n-a,i),
		ans+=cnt[i]*calc(m-i+1,a),ans%=mod;
	println(ans);
}