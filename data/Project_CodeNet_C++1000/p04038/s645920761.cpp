#include<bits/stdc++.h>
using namespace std;

const int N = 2020, M = N * N, MOD = 1000 * 1000 * 1000 + 7;

int sum(int a, int b) {
	a += b;
	if(a < 0)
		a += MOD;
	else if(a >= MOD)
		a -= MOD;
	return a;
}

void _sum(int &a, int b) {
	a = sum(a, b);
}

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

void _mul(int &a, int b) {
	a = mul(a, b);
}

int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int n, k, dp[N], fac[M], pow_fac[M];

int f(int a) {
	return power(a, MOD - 2);
}

int choose(int a, int b) {
	return (a > b? 0: mul(fac[b], mul(pow_fac[a], pow_fac[b - a])));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	fac[0] = 1;
	for (int i = 1; i < M; i++)
		fac[i] = mul(fac[i - 1], i);
	for (int i = 0; i < M; i++)
		pow_fac[i] = f(fac[i]);
	cin >> n >> k;
	if(k == 1) {
		cout << 1;
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int val = choose(j, i);
			_mul(val, choose(j * k - j, i * k - j));
			_mul(val, mul(fac[j * (k - 1)], f(power(fac[k - 1], j))));
			_mul(val, dp[i - j]);
			dp[i] = sum(dp[i], (j & 1? 1: -1) * val);
		}
	}
	cout << dp[n];
	return 0;
}