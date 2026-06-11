#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	ll N, W;
	cin >> N >> W;

	vector<pair<ll, ll>> item(N);
	ll w0;
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		if (i == 0)w0 = w;
		item[i] = { w - w0,v };
	}

	//dp[i][j][k] i個まで見てj個詰め込んで重さk にしたときの最大価値
	vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(4 * N + 10, 0)));
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)for (int k = 0; k < 4 * N; k++) {
		dp[i + 1][j + 1][k + item[i].first] = max(dp[i][j][k] + item[i].second, dp[i + 1][j + 1][k + item[i].first]);
		dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
	}

	ll ans = 0;
	for (int i = 0; i <= N; i++)for (int j = 0; j < 4 * N; j++) {
		if (i * w0 + j <= W)ans = max(ans, dp[N][i][j]);
	}
	cout << ans << endl;

}