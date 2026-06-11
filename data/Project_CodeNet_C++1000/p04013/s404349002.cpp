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
	int N, A;
	cin >> N >> A;
	vector<int> x(N);
	for (int i = 0; i < N; i++)cin >> x[i];
	//i個目まで見て、j個選んで和がkになるときの場合の数
	vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(3000, 0)));
	dp[0][0][0] = 1;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)for (int k = 0; k < 2600; k++) {
		dp[i + 1][j][k] += dp[i][j][k];
		dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp[N][i][A * i];
	}
	cout << ans << endl;
}