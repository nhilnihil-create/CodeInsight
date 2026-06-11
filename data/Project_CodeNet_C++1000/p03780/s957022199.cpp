#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, A[5000], L, R;
	cin >> N >> K;
	L = -1, R = N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	while (R - L > 1) {
		long long MID = (L + R) / 2;
		static bool DP[5010][5010] = {};
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < K; j++) DP[i][j] = false;
		}
		DP[0][0] = true;
		for (int i = 0; i < N; i++) {
			if (i == MID) {
				for (int j = 0; j < K; j++) {
					DP[i + 1][j] = DP[i][j];
				}
				continue;
			}
			for (int j = 0; j < K; j++) {
				if (DP[i][j]) {
					DP[i + 1][j] = true;
					if (j + A[i] < K) DP[i + 1][j + A[i]] = true;
				}
			}
		}
		bool check = false;
		for (int i = max(0LL, K - A[MID]); i < K; i++) {
			if (DP[N][i]) check = true;
		}
		if (check) R = MID;
		else L = MID;
	}
	cout << R << endl;
}