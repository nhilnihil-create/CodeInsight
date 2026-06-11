
// D - Simple Knapsack

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll w[101];
ll v[101];
map<ll, ll> dp[101]; // dp[i] map(tw, tv): i個目までの物で重さの合計がtwの時の価値の総和の最大値tv

int main() {
	int N, W;
	cin >> N >> W;

	for (int i=1; i<=N; i++) {
		cin >> w[i] >> v[i];
	}

	dp[0][0] = 0;

	for (int i=0; i<N; i++) {
		//cout << "i=" << i << endl; // **** debug ****
		for (auto& itr : dp[i]) {
			ll tw = itr.first;
			ll tv = itr.second;
			//cout << "tw=" << tw << " tv=" << tv << endl; // **** debug ****

			// i個目を使わない遷移
			dp[i+1][tw] = max(dp[i+1][tw], dp[i][tw]);

			// i個目を使う遷移
			if (tw + w[i+1] <= W) {
				dp[i+1][tw + w[i+1]] = max(dp[i+1][tw + w[i+1]], dp[i][tw] + v[i+1]);
			}
		}
	}

	ll ans = 0;
	for (auto& itr : dp[N]) {
		ans = max(ans, itr.second);
	}

	cout << ans << endl;

	return 0;
}