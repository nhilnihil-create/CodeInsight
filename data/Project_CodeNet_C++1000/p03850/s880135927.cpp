#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fst first
#define snd second
const ll mod = 1000000007;
const ll INF = mod * mod;

int main(){
	ll n;
	ll a[100010];
	bool m[100010];
	ll dp[100010][3];

	cin >> n;
	m[0] = 0;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		char c;
		cin >> c;
		if (c == '+')m[i] = false;
		else m[i] = true;
		cin >> a[i];
	}
	dp[0][0] = a[0]; dp[0][1] = -INF; dp[0][2] = -INF;
	for (int i = 1; i < n; i++) {
		if (m[i]) {
			dp[i][0] = -INF;
			dp[i][1] = -a[i] + max(dp[i - 1][1], dp[i - 1][0]);
			if (dp[i - 1][1] != -INF || dp[i - 1][2] != -INF) {
				dp[i][2] = a[i] + max(dp[i - 1][1], dp[i - 1][2]);
			}
			else {
				dp[i][2] = -INF;
			}
		}
		else {
			dp[i][0] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = -a[i] + dp[i-1][1];
			if (dp[i - 1][2] != -INF) {
				dp[i][2] = a[i] + dp[i - 1][2];
			}
			else {
				dp[i][2] = -INF;
			}
		}
	}
	ll ans = dp[n - 1][2];
	ans = max(ans, dp[n - 1][1]);
	ans = max(ans, dp[n - 1][0]);
	cout << ans << endl;
	return 0;
}
