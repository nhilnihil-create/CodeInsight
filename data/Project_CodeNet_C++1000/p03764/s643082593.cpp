#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

long long x[100005];
long long y[100005];

const ll mod = (ll)1e9+7;

ll mul(ll a, ll b)
{
	return (a*b)%mod;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 0 ; i < n ; i++)
	{
		scanf("%lld",&x[i]);
	}
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%lld",&y[i]);
	}

	ll a = 0, b = 0;

	for(int i = 0; i < n ; i++)
	{
		a += mul(x[i],i) - mul(x[i], n-i-1);
		a += mod;
		a %= mod;
	}
	for(int i = 0; i < m ; i++)
	{
		b += mul(y[i],i) - mul(y[i], m-i-1);
		b += mod;
		b %= mod;
	}
	printf("%lld\n",mul(a,b));
	return 0;
}
