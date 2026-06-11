#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << (x) << endl
#define For(i, j, k) for (int i = j; i <= k; ++ i)
#define Forr(i, j, k) for (int i = j; i >= k; -- i)

using namespace std;

inline void File() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
}

const int N = 2e5 + 10, mod = 1e9 + 7;
int fac[N], inv[N], n, m, a, b;

inline int qpow(int a, int b) {
	static int res;
	for (res = 1; b; b >>= 1, a = 1ll * a * a % mod)
		if (b & 1) res = 1ll * res * a % mod;
	return res;
}

inline void Init(int n) {
	fac[0] = 1; For(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = qpow(fac[n], mod - 2);
	Forr(i, n - 1, 0) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

inline int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

inline int add(int a, int b) { return a + b > mod ? a + b - mod : a + b; }

int main() {
	 Init(N - 5);
	
	cin >> n >> m >> a >> b;

	int ans = 0, x = n - a, y = b + 1;

	for (; x > 0 && y <= m; -- x, ++ y) 
		ans = add(ans, 1ll * C(x + y - 2, x - 1) * C(n + m - x - y, n - x) % mod);

	cout << ans << endl;
	return 0;
}
