#include<bits/stdc++.h>
using namespace std;

const int N = 2000 + 20, M = 4 * 1000 * 1000 + 20, mod = 1e9 + 7;
int n, k, fact[M], factRev[M], dp[N][N];

int sum(int a, int b) {
	return ((1LL * a + b) % mod + mod) % mod;
}

int mul(int a, int b) {
	return ((1LL * a * b) % mod + mod) % mod;
}

int pw(int a, int b) {
	int res = 1, tmp = a;
	while (b) {
		if (b & 1)
			res = mul(res, tmp);
		tmp = mul(tmp, tmp);
		b >>= 1;
	}
	return res;
}

int c(int a, int b) {
	return mul(fact[a], mul(factRev[b], factRev[a - b]));
}

void prepros() {
	fact[0] = 1;
	for (int i = 1; i < M; i++)
		fact[i] = mul(fact[i - 1], i);
	factRev[M - 1] = pw(fact[M - 1], mod - 2);
	for (int i = M - 2; ~i; i--)
		factRev[i] = mul(factRev[i + 1], i + 1);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	prepros();
	if (k == 1)
		return cout << 1 << endl, 0;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j)
				dp[i][j] = sum(dp[i][j], mul(dp[i][j - 1], c((n * k) - ((j - 1) * (k - 1)) - i - 1, k - 2)));
		}
	return cout << mul(dp[n][n], fact[n]) << "\n", 0;

}
