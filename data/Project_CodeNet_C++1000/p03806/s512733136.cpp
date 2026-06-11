#include "bits/stdc++.h"
using namespace std;
int main() {
	int N, Ma, Mb;
	cin >> N >> Ma >> Mb;
	int cnst = 4000;
	int dp[45][8005];
	for (int i = 0; i < 45; ++i) {
		for (int j = 0; j < 8005; ++j) {
			dp[i][j] = 1e9;
		}
	}
	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		int diff = a * Mb - b * Ma;
		dp[i + 1][cnst + diff] = min(dp[i + 1][cnst + diff],c);
		for (int j = 0;j<8005; ++j) {
			dp[i + 1][j] = min(dp[i+1][j],dp[i][j]);
			dp[i + 1][j + diff] = min(dp[i+1][j+diff],dp[i][j]+c);
		}
	}
	if (dp[N][cnst]<1e9) {
		cout << dp[N][cnst]<<endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}