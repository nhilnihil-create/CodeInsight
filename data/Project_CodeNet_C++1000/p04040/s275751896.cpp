#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, MOD = 1e9 + 7;
int n, m, a, b, ans, f[N], divs[N];
int ksm (int x, int y) {
	int now = x, ret = 1;
	while (y) {
		if (y & 1)
			ret = ret * now % MOD;
		now = now * now % MOD;
		y >>= 1;
	}
	return ret;
}
int C (int x, int y) {
	return (f[x] * divs[y] % MOD) * divs[x - y] % MOD;
}
int ways (int sa, int sb, int fa, int fb) {
	int x = (fa - sa) + (fb - sb), y = (fa - sa);
	return C (x, y);
}
signed main () {
	f[0] = 1;
	divs[0] = 1;
	for (int i = 1; i <= 2e5; i ++) {
		f[i] = f[i - 1] * i % MOD;
		divs[i] = ksm (f[i], MOD - 2);
	}
	scanf ("%lld%lld%lld%lld", &n, &m, &a, &b);
	ans = ways (1, 1, n, m);
	for (int i = 1; i <= b; i ++) {
		int now = ways (1, 1, n - a, i) * ways (n - a + 1, i, n, m) % MOD;
		while (ans < now)
			ans += MOD;
		ans -= now;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
