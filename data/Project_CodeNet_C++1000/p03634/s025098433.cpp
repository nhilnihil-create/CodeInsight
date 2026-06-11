#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<pair<int,ll>> to[100000];
	rep(i,n-1) {
		int a,b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		to[a].push_back(pair<int, ll>(b,c));
		to[b].push_back(pair<int, ll>(a,c));
	}
	int q,k;
	cin >> q >> k;
	k--;

	// 各点から頂点Kまでの距離を計算
	queue<int> que;
	que.push(k);
	vector<bool> visited(n,false);
	visited[k] = true;
	vector<ll> dist(n,0);
	while(!que.empty()) {
		int now = que.front();
		que.pop();
		for (pair<int,ll> nei : to[now]) {
			int next = nei.first;
			ll d = nei.second;
			if (!visited[next]) {
				dist[next] = dist[now] + d;
				visited[next] = true;
				que.push(next);
			}
		}
	}
	//rep(i,n) printf("%lld, %lld\n", i, dist[i]);

	rep(i,q) {
		int x,y;
		cin >> x >> y;
		x--, y--;
		ll ans = 0;
		// 距離を計算
		ans = dist[x] + dist[y];
		cout << ans << endl;
	}
	return 0;
}
