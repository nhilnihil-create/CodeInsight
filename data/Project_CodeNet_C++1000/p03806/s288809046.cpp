#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e12;

int main() {
	ll n, ma, mb; cin >> n >> ma >> mb;
	vector<vector<ll>>dp(405, vector<ll>(405, INF));
	dp[0][0] = 0;
	for (ll k = 0, a, b, c; k < n; k++) {
		cin >> a >> b >> c;
		for (ll i = 404; i >= a; i--) {
			for (ll j = 404; j >= b; j--)dp[i][j] = min(dp[i][j], dp[i - a][j - b] + c);
		}
	}
	ll ans = INF;
	for (ll i = 1; i * max(ma, mb) < 405; i++) {
		ans = min(ans, dp[i * ma][i * mb]);
	}
	cout << (ans != INF ? ans : -1) << endl;

	return 0;
}