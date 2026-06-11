#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define MX 200005

using namespace std;

typedef long long ll;

ll fac[MX], faci[MX];

ll qpow(ll x, ll t)
{
	ll ans = 1;
	while(t)
	{
		if(t & 1) ans = ans*x%MOD;
		t = t>>1;
		x = x*x%MOD;
	}
	return ans;
}

ll inv(ll x)
{
	return qpow(x, MOD-2);
}

void init()
{
	fac[0] = 1;
	for(int i=1; i<MX; i++) fac[i] = fac[i-1]*i%MOD;
	faci[MX-1] = inv(fac[MX-1]);
	for(int i=MX-1; i>=1; i--) faci[i-1] = faci[i]*i%MOD;
}

ll C(int n, int m)
{
	if(n<0 || m<0 || m>n) return 0;
	return fac[n] * faci[m] % MOD * faci[n-m] % MOD;
}

ll dway[MX];

int main()
{
	int n, m, a, b;
	init();
	scanf("%d%d%d%d", &n, &m, &a, &b);
	ll ans = 0;
	for(int i=b; i>=1; i--) ans = (ans+C(m-i+a-1, a-1)*C(i-1+n-a-1, n-a-1))%MOD;
	printf("%lld\n", (C(n+m-2, m-1) - ans + MOD) % MOD);
	return 0;
}