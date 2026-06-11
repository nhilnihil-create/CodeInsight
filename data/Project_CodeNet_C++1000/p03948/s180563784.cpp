#include <bits/stdc++.h>
using namespace std;

using lli = long long;
using pii = pair<int, int>;
using pll = pair<lli, lli>;
using Double = long double;
template<typename T>
using Vector = vector<vector<T>>;
template<typename T>
using Prior = priority_queue<T>;
template<typename T>
using prior = priority_queue<T, vector<T>, greater<T>>;

#define IOS() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define Push push_back
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()

void solve() {
	lli n, t;
	cin >> n >> t;

	vector<lli> cost(n);
	for (auto &x : cost) cin >> x;

	lli nowMax = 0, nowPro = 0, ans = 0;
	for (int i = n-1; i >= 0; --i) {
		nowMax = max(nowMax, cost[i]);
		if (nowMax - cost[i] == nowPro) {
			++ans;
		}
		else if (nowMax - cost[i] > nowPro) {
			nowPro = nowMax - cost[i];
			ans = 1;
		}
	}

	cout << ans << "\n";
}

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}