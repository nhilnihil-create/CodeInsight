#include "bits/stdc++.h"
using namespace std;

constexpr long long MOD = 1000000007;

int main() {
	long long N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<long long> DP(N + 1, 0), DPSUM(N + 1, 0);
	DP[0] = 1, DP[1] = 1, DPSUM[0] = 1, DPSUM[1] = 2;
	for (int i = 2; i <= N; i++) {
		DP[i] = (DPSUM[i - 1] - DP[i - 2] + MOD) % MOD;
		DPSUM[i] = (DPSUM[i - 1] + DP[i]) % MOD;
	}
	long long ANS = (DP[N] + DP[N - 1] * (N - 1) + DPSUM[N - 2]) % MOD;
	for (int i = 0; i < N - 2; i++) {
		ANS += DPSUM[N - 2] - DPSUM[i];
		ANS %= MOD;
	}
	ANS = (ANS + DPSUM[N - 2] * (((N - 1) * (N - 1)) % MOD)) % MOD;
	cout << ANS << endl;
}