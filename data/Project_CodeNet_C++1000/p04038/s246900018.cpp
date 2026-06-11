#include <iostream>
using namespace std;

long long N, K, fact[5000009], inv[5000009], INV[5000009], dp[2009][2009], mod = 1000000007;

long long ncr(long long n, long long r, long long m) {
	return (((fact[n] * inv[r]) % m)*inv[n - r]) % m;
}

int main() {
	cin >> N >> K; if (N == 1 || K == 1) { cout << "1" << endl; return 0; }
	fact[0] = 1; inv[0] = 1; INV[0] = 1; INV[1] = 1;
	for (int i = 2; i <= 5000000; i++) INV[i] = (mod - (mod / i)*INV[mod%i] + mod*mod) % mod;
	for (int i = 1; i <= 5000000; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 1; i <= 5000000; i++) inv[i] = (inv[i - 1] * INV[i]) % mod;
	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0) continue;
			if (i < N) {
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= mod;
			}
			if (i > j) {
				long long A = K - 2;
				long long B = (N - i) + (N - j - 1)*(K - 1);
				dp[i][j + 1] += dp[i][j] * ncr(A + B, A, mod);
				dp[i][j + 1] %= mod;
			}
		}
	}
	cout << (dp[N][N] * fact[N]) % mod << endl;
	return 0;
}