#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), ans(n);
	rep(i, n) cin >> a[i];
	priority_queue<pair<ll, int>> pq;
	rep(i, n) {
		pq.emplace(a[i], i);
	}
	ll num = 0;
	int min_index = n;
	while(!pq.empty()) {
		auto now = pq.top();
		pq.pop();
		min_index = min(min_index, now.second);
		num++;
		while((!pq.empty()) && (pq.top().first == now.first)) {
			auto tmp = pq.top();
			pq.pop();
			num++;
			min_index = min(min_index, tmp.second);
		}
		ll add;
		if(!pq.empty()) {
			auto next = pq.top();
			add = now.first - next.first;
		} else {
			add = now.first;
		}
		ans[min_index] += num * add;
	}
	rep(i, n) cout << ans[i] << endl;
	return 0;
}