#include "bits/stdc++.h"
using namespace std;

long long MOD = 1000000007;

long long Calc(long long A, long long B) {
	if (B == 0) return 1;
	if (B % 2 == 0) {
		long long C = Calc(A, B / 2);
		return (C * C) % MOD;
	}
	return (A * Calc(A, B - 1)) % MOD;
}

int main() {
	int N;
	string S;
	static long long DP[5010][5010] = {};
	cin >> N >> S;
	DP[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
		DP[i][0] %= MOD;
		for (int j = 1; j <= N; j++) {
			DP[i][j] = DP[i - 1][j - 1] * 2 + DP[i - 1][j + 1];
			DP[i][j] %= MOD;
		}
	}
	cout << (DP[N][S.size()] * Calc(Calc(2, MOD - 2), S.size())) % MOD << endl;
}