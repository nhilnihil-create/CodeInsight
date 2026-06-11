
// D - Maximum Average Sets

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

long double dp[51][51]; // dp[i][j]: i番目の品物の中からj個選んだときの合計の最大値
ll dp_cnt[51][51]; // dp_cnt[i][j]: i番目の品物の中からj個選んだときの合計を最大にする選び方の数
long double v[51];

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	for (int i=1; i<=N; i++) {
		cin >> v[i];
	}

	dp_cnt[0][0] = 1;

	for (int i=0; i<N; i++) {
		for (int j=0; j<=i; j++) {
			// 品物iを選ばない更新
			if (dp[i+1][j] < dp[i][j]) {
				dp[i+1][j] = dp[i][j];
				dp_cnt[i+1][j] = dp_cnt[i][j];
			} else if (dp[i+1][j] == dp[i][j]) {
				dp_cnt[i+1][j] += dp_cnt[i][j];
			}

			// 品物iを選ぶ更新
			if (dp[i+1][j+1] < dp[i][j] + v[i+1]) {
				dp[i+1][j+1] = dp[i][j] + v[i+1];
				dp_cnt[i+1][j+1] = dp_cnt[i][j];
			} else if (dp[i+1][j+1] == dp[i][j] + v[i+1]) {
				dp_cnt[i+1][j+1] += dp_cnt[i][j];
			}
		}
	}

	vector<ll> K; // 選んだ品物の価値の平均が最大になるときの選んだ数（複数の場合あり）
	long double max_mean = 0;
	long double tmp_mean;
	for (int i=A; i<=B; i++) {
		tmp_mean = dp[N][i] / i;
		if (tmp_mean > max_mean) {
			max_mean = tmp_mean;
			K.clear();
			K.push_back(i);
		} else if (tmp_mean == max_mean) {
			K.push_back(i);
		}
	}

	ll num_choice = 0;
	for (ll k : K) {
		num_choice += dp_cnt[N][k];
	}

	cout << fixed << setprecision(10);
	cout << max_mean << endl;
	cout << num_choice << endl;

	// **** debug ****
	/*
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=i; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=i; j++) {
			cout << dp_cnt[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}