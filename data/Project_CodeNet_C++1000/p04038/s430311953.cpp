#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2005, M = 4000005, mo = 1e9 + 7;
int n, k; ll ans;
ll fac[M], ivf[M], inv[M], f[N][N];
void prep () {
	fac[0] = ivf[0] = 1;
	fac[1] = ivf[1] = inv[1] = 1;
	for (int i = 2; i < M; ++i) {
		fac[i] = fac[i - 1] * i % mo;
		inv[i] = mo - 1ll * mo / i * inv[mo % i] % mo;
		ivf[i] = ivf[i - 1] * inv[i] % mo;
	}
}
ll C (int n, int r) {
	if (r < 0 || n < r)
		return 0;
	return fac[n] * ivf[r] % mo * ivf[n - r] % mo;
}
ll get (int a, int b) {
	return C(a + b, a);
}
int main () {
	cin >> n >> k, prep();
	if (k == 1)
		return puts("1"), 0;
	f[n][n] = 1;
	for (int i = n; ~i; --i)
		for (int j = n; ~j; --j) {
			if (i)
				f[i - 1][j] += f[i][j], f[i - 1][j] %= mo;
			if (i <= j - 1 && j) {
				f[i][j - 1] += f[i][j] * get(k - 2, (k - 1) * (j - 1) + i);
				f[i][j - 1] %= mo;
			}
		}
	cout << f[0][0] * fac[n] % mo << endl;
	return 0;
}