#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 100010;
const int MOD = 1000000007;

int n, m;

lli x[MAXN];
lli y[MAXN];

int main()
{
	scanf("%d %d",&n,&m);

	for(int i = 1 ; i <= n ; i++)
		scanf("%lld",&x[i]);

	for(int i = 1 ; i <= m ; i++)
		scanf("%lld",&y[i]);

	lli ans = 0;
	lli sumY = 0;

	for(int i = 1 ; i <= m ; i++)
	{
		lli val = y[i]*(i - 1);
		val -= y[i]*(m - i);

		sumY += val;
		sumY %= MOD;
	}

	for(int i = 1 ; i <= n ; i++)
	{
		lli val = x[i]*sumY;
		val %= MOD;
		val *= (i - 1);

		ans += val;
		ans %= MOD;

		val = x[i]*sumY;
		val %= MOD;
		val *= (n - i);

		ans -= val;
		ans %= MOD;
	}

	ans %= MOD;
	ans += MOD;
	ans %= MOD;

	printf("%lld\n",ans);
}