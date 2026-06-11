#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

string N; int K;
vector<int> can_use(10, true);
int mn_use;

void input(void) {
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int di; cin >> di;
		can_use[di] = false;
	}
	for (int i = 0; i < 10; ++i) {
		if (can_use[i]) {
			mn_use = i;
			break;
		}
	}
}

int main(void) {
	constexpr int INF = (1 << 25);
	input();
	vector<vector<int>> dp(N.size() + 1, vector<int>(2, 0));
	for (int i = 1; i < 10; ++i) {
		if (can_use[i]) {
			dp[0][1] = i;
			break;
		}
	}
	for (int i = 1; i <= N.size(); ++i) {
		// dp[i][0]の確定
		if (dp[i - 1][0] == INF || !can_use[N[i - 1] - '0'])
			dp[i][0] = INF;
		else dp[i][0] = dp[i - 1][0] * 10 + (N[i - 1] - '0');
		// dp[i][1]の確定
		dp[i][1] = min(dp[i - 1][1] * 10 + mn_use, INF);
		int d = -1;
		for (int j = (N[i - 1] - '0') + 1; j < 10; ++j) {
			if (can_use[j]) {
				d = j;
				break;
			}
		}
		if (d != -1) 
			dp[i][1] = min(dp[i][1], dp[i - 1][0] * 10 + d);
	}
	cout << min(dp[N.size()][0], dp[N.size()][1]) << endl;
	return 0;
}