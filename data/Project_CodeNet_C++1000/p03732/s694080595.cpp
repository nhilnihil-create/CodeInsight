#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, ans = 0;
map<int, int, greater<int>> dp;

int main() {
	cin >> n >> m;
	dp[0] = 0;
	for (int i = 0, w, v; i < n; ++i) {
		cin >> w >> v;
		for (auto &x : dp)
			if (x.first + w <= m)
				dp[x.first + w] = max(dp[x.first + w], dp[x.first] + v);
	}
	for (auto &x : dp)
		ans = max(ans, x.second);
	cout << ans << endl;
}
