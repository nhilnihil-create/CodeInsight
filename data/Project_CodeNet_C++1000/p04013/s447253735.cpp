#include "bits/stdc++.h"
using namespace std;

long long dp[51][5001];
int main() {
	int N, A;
	cin >> N >> A;
	vector<int>X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
		X[i] -= A;
	}
	dp[0][2500] = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5001; ++j) {
			if (0 != dp[i][j]) {
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j + X[i]] += dp[i][j];
			}
		}
	}
	cout << dp[N][2500] - 1 << endl;
	return 0;
}