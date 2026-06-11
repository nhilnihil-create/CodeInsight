#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sw, sv;

ll dfs(ll now_limit, vector<vector<ll>> &wv, int n, ll rest, ll cnt) {
	if(n == 4) {
		return cnt;
	}
	ll ans = 0;
	for(int i=0;i<=min(now_limit, (ll)wv[n].size()-1);i++) {
		ll next_limit = (rest - i * (n + sw)) / (n + 1 + sw);
		ans = max(ans, dfs(next_limit, wv, n + 1, rest - i * (n + sw), cnt + wv[n][i]));
	}
	return ans;
}

signed main() {
	int N;
	ll W;
	cin >> N >> W;
	vector<vector<ll>> wv(5);
	cin >> sw >> sv;
	wv[0].push_back(sv);
	for(int i=0;i<5;i++) wv[i].push_back(LLONG_MAX);
	for(int i=1;i<N;i++) {
		ll w, v;
		cin >> w >> v;
		wv[w-sw].push_back(v);
	}
	// 各重さでそれぞれ何個選ぶか決める
	for(int i=0;i<4;i++) {
		sort(wv[i].rbegin(), wv[i].rend());
	}
	for(int i=0;i<5;i++) wv[i][0] = 0;

	// 累積和
	for(int i=0;i<4;i++) {
		for(int j=1;j<wv[i].size();j++) {
			wv[i][j] += wv[i][j-1];
		}
	}
	ll now_limit = W / sw;
	cout << dfs(now_limit, wv, 0, W, 0) << endl;
}