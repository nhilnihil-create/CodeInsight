#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e12;

int main() {
	ll i, j, k;
	ll n, ma, mb;
	cin >> n >> ma >> mb;
	vector<vector<ll>> dp(404, vector<ll>(404, INF));
	dp[0][0] = 0;
	for (k = 0; k < n; k++) {
		ll a, b, c;
		cin >> a >> b >> c;
		for (i = 403; i >= a; i--) {
			for (j = 403; j >= b; j--) {
				dp[i][j] = min(dp[i][j], dp[i - a][j - b] + c);
			}
		}
	}
	ll ans = INF;
	for (i = 1; i * max(ma, mb) < 404; i++) {
		ans = min(ans, dp[i * ma][i * mb]);
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}