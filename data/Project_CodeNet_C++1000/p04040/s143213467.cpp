#include "bits/stdc++.h"
using namespace std;

int MOD = 1000000007;
static long long F[200010] = {}, RF[200010] = {};

long long Calc(int a, int b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		long long x = Calc(a, b / 2);
		return (x * x) % MOD;
	}
	return (a * Calc(a, b - 1)) % MOD;
}

long long Comb(int a, int b) {
	long long x = F[a];
	x *= RF[b];
	x = x % MOD;
	x *= RF[a - b];
	return x % MOD;
}

int main() {
	int H, W, A, B;
	long long ans = 0;
	cin >> H >> W >> A >> B;
	F[0] = 1, RF[0] = 1;
	for (int i = 1; i <= H + W - 2; i++) {
		F[i] = (F[i - 1] * i) % MOD;
		RF[i] = (RF[i - 1] * Calc(i, MOD - 2)) % MOD;
	}
	for (int i = B; i < W; i++) {
		long long count = 1;
		count *= Comb(H - A - 1 + i, i);
		count = count % MOD;
		count *= Comb(W + A - 2 - i, A - 1);
		count = count % MOD;
		ans += count;
		ans = ans % MOD;
	}
	cout << ans;
}