#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int mod = 1e9 + 7;

int n, k;
int f[N][N];
int fac[N * N], ifac[N * N];

void add(int &x,int y) {
	x += y; if (x >= mod) x -= mod;
}

int mul(int x,int y) {
	return (long long) x * y % mod;
}

int pw(int x,int y) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = mul(ret, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ret;
}

int C(int n,int k) {
	if (n < k || k < 0) return 0;
	return mul(fac[n], mul(ifac[k], ifac[n - k]));
}

int main() {
	ios_base::sync_with_stdio(false);
	fac[0] = 1; 
	for (int i = 1; i < N * N; ++i) fac[i] = mul(fac[i - 1], i);
	ifac[N * N - 1] = pw(fac[N * N - 1], mod - 2);
	for (int i = N * N - 2; i >= 0; --i) ifac[i] = mul(ifac[i + 1], i + 1);
	cin >> n >> k;
	if (k == 1) return cout << 1 << '\n',0;
	
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j < i) add(f[i][j], f[i - 1][j]);
			if (j > 0) add(f[i][j], mul(f[i][j - 1], C(n * k - i - (j - 1) * (k - 1) - 1, k - 2))); 
		}
	}
	cout << mul(f[n][n], fac[n]) << '\n';
}