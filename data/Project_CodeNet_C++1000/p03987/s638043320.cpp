#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> inv(n);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		inv[x-1] = i;
	}
	set<int> act;
	act.insert(-1);
	act.insert(n);
	ll res = 0;
	for (int raw = 0; raw < n; ++raw) {
		int pos = inv[raw];
		auto it = act.lower_bound(pos);
		ll right = *it - pos;
		--it;
		ll left = pos - *it;
		res += right*left*(raw+1ll);
		act.insert(pos);
	}
	cout << res << "\n";
}
