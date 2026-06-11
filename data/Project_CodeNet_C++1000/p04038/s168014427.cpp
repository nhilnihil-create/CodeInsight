#include <iostream>
#include <cstdio>
using namespace std;

const int MOD(1000000007);
int n, k;
int fac[4000000], inv_fac[4000000], dp[2001];


int Power(long long a, int b)
{
	long long ret(1ll);
	
	while (b) {
		b & 1 && (ret *= a);
		ret >= MOD && (ret %= MOD);
		a *= a;
		a >= MOD && (a %= MOD);
		b >>= 1;
	}
	return ret;
}


int main()
{
	register long long lt;
	int t;
	
	scanf("%d%d", &n, &k);
	if (k == 1) {
		printf("1\n");
		return 0;
	}
	fac[0] = 1;
	t = n * k;
	for (int i = 1; i < t; ++i) {
		lt = (long long)i * fac[i - 1];
		fac[i] = lt < MOD ? lt : lt % MOD; 
	}
	inv_fac[t - 1] = Power((long long)fac[t - 1], MOD - 2);
	for (int i = t - 2; i; --i) {
		lt = (long long)(i + 1) * inv_fac[i + 1];
		inv_fac[i] = lt < MOD ? lt : lt % MOD;
	}
	inv_fac[0] = 1;
	dp[0] = 1;
	t = -2;
	for (int i = 1; i <= n; ++i) {
		t += k - 1;
		for (int j = 0; j <= i; ++j) {
			++t;
			lt = (long long)fac[t] * inv_fac[t - k + 2];
			lt >= MOD && (lt %= MOD);
			lt *= (long long)inv_fac[k - 2];
			lt >= MOD && (lt %= MOD);
			lt *= (long long)dp[j];
			j && (lt += dp[j - 1]);
			dp[j] = lt < MOD ? lt : lt % MOD;
		}
		t -= i + 1;
	}
	lt = (long long)dp[n] * fac[n] % MOD;
	printf("%lld\n", lt);
	return 0;
}

