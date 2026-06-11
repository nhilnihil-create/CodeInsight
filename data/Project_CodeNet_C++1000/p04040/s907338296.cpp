#include <iostream>
#include <algorithm>
#include <cmath>

const int MAX = 200010;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

long long COM(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long h, w, a, b;
int main()
{
	COMinit();
	std::cin >> h >> w >> a >> b;

	long long ans = 0;
	for (long long i = b + 1; i <= w; ++i) {
		long long mh = h - a;
		long long w1 = i - 1;
		long long h1 = mh - 1;
		long long route1 = COM(w1 + h1, w1);

		long long w2 = w - i;
		long long h2 = h - (mh + 1);
		long long route2 = COM(w2 + h2, w2);

		ans = (ans + route1 * route2) % MOD;
	}

	std::cout << ans << std::endl;
	return 0;
}
