#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = INF;
	rep(bit, (1 << n)) {
		vector<int> s;
		rep(i, n) {
			if (bit & (1 << i)) {
				s.push_back(i);
			}
		}
		if (s.size() < k) continue;
		vector<ll> t(n);
		rep(i, s.size()) {
			int u = s[i];
			rep(j, u) {
				if (a[j] + t[j] >= a[u] + t[u]) {
					t[u] = a[j] + t[j] - a[u] + 1;
				}
			}
		}
		ll mn = 0;
		rep(i, n) mn += t[i];
		ans = min(ans, mn);
	}
	cout << ans << endl;
	return 0;
}