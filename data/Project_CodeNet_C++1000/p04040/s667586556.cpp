#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;
const long long MOD = 1e9 + 7;

long long fat[MAXN];
long long ifat[MAXN];
long long inv[MAXN];

long long fexp (long long b, long long e) {
	long long ans = 1;
	while (e) {
		if (e & 1) ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1LL;
	}

	return ans;
}

long long perm (long long x, long long y) {
	if (x < 0 || y < 0) return 0;
	long long ans = (ifat[x] * ifat[y]) % MOD;
	ans = (ans * fat[x + y]) % MOD;
	return ans;
}

int main () {

	fat[0] = 1; ifat[0] = 1;
	for (long long i = 1; i < MAXN; ++i) {
		fat[i] = (fat[i - 1] * i) % MOD;
		ifat[i] = fexp (fat[i], MOD - 2);
	}

	long long h, w, a, b;
	cin >> h >> w >> a >> b;

	long long ans = 0;
	for (int i = 0; i < h - a; ++i)
		ans += (perm (b, i) * perm (w - b - ((i == h - a - 1) ? 1 : 2), h - i - 1)) % MOD;

	cout << ans % MOD << endl;

	return 0;
}