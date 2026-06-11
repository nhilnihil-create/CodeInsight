
// D - Mixing Experiment

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int I_MAX = 40;
const int W_MAX = 400;

// dp[i][j][k]: i個目までの薬品を考慮したときの、Aがjグラム、Bがkグラムの時の最小予算
int dp[I_MAX+1][W_MAX+1][W_MAX+1];
int a[I_MAX+1], b[I_MAX+1], c[I_MAX+1];

int main() {
	int N, Ma, Mb;
	cin >> N >> Ma >> Mb;

	for (int i=1; i<=N; i++) {
		cin >> a[i] >> b[i] >> c[i]; // 1-index
	}

	// INFで初期化
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=W_MAX; j++) {
			for (int k=0; k<=W_MAX; k++) {
				dp[i][j][k] = INF;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int i=1; i<=N; i++) {
		for (int j=0; j<=W_MAX; j++) {
			for (int k=0; k<=W_MAX; k++) {
				// i個目を使う場合
				int prev_j = j - a[i];
				int prev_k = k - b[i];
				if (prev_j >= 0 && prev_k >= 0) {
					if (dp[i-1][prev_j][prev_k] != INF) {
						dp[i][j][k] = min(dp[i][j][k], dp[i-1][prev_j][prev_k] + c[i]);
					}
				}

				// i個目を使わない場合
				dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
			}
		}
	}

	int min_cost = INF;
	// jとkに0を含めないことに注意
	for (int j=1; j<=W_MAX; j++) {
		for (int k=1; k<=W_MAX; k++) {
			if (j * Mb == k * Ma) {
				min_cost = min(dp[N][j][k], min_cost);
			}
		}
	}

	if (min_cost == INF) min_cost = -1;

	cout << min_cost << endl;

	return 0;
}