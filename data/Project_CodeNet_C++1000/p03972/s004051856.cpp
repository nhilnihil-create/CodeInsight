#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int H, W; cin >> W >> H;
	ll res = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
	for (int i = 0; i < W; i++) {
		ll x; cin >> x; q.emplace(x, 0);
	}
	for (int i = 0; i < H; i++) {
		ll x; cin >> x; q.emplace(x, 1);
	}
	vector<ll> cnt{H+1, W+1};
	while (q.size()) {
		auto p = q.top(); q.pop();
		ll x = p.first; int i = p.second;
		res += x * cnt[i];
		cnt[1-i]--;
	}
	cout << res << endl;
}