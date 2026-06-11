#include "bits/stdc++.h"
using namespace std;

int dp[5010][5010];
int dpR[5010][5010];
//int dpSumR[5010][5010];
int A[5010];
int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	dp[0][0] = 1;
	{
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= K; ++j) {
				if (dp[i][j]) {
					dp[i+1][j] = 1;
					if (j + A[i] <= K) {
						dp[i + 1][j + A[i]] = 1;
					}
				}
			}
		}
	}
	dpR[0][1] = 1;
	{
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <= K; ++j) {
				if (dpR[i][j+1]) {
					dpR[i+1][j+1] = 1;
					if (j + A[N - 1 - i] <= K) {
						dpR[i + 1][j + A[N - 1 - i]+1] = 1;
					}
				}
			}
		}
	} 
	{
		for (int i = 0; i < N+1; ++i) {
			for (int j = 1; j < K+2; ++j) {
				dpR[i][j] += dpR[i][j - 1];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0;j<K;++j) {
			if (dp[i][j]) {
				if (dpR[N-i-1][K-j] > dpR[N-i-1][max(0, K - A[i]-j)]) {
					ans++;
					break;
				}
			}
		}
	}
	cout << N - ans <<  endl;
	return 0;
}