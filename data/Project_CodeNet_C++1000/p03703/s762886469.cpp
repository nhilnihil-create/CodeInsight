#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// sum_(i = l to r-1) a_i / (r-l) >= K
// sum >= K * r - K * l
// pref_r - pref_l >= K * r - K * l

const int MAXN = 3e5;
int N;
ll K;

ll v[MAXN];

vector<ll> vals;

int lookup(ll a) {
	return int(lower_bound(vals.begin(), vals.end(), a) - vals.begin());
}

int bit[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	v[0] = 0;
	vals.push_back(v[0]);
	ll s = 0;
	for (int i = 1; i <= N; i++) {
		ll a; cin >> a;
		s += a;
		v[i] = s - K * i;
		vals.push_back(v[i]);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		int a = lookup(v[i]);
		for (int j = a+1; j; j -= (j & -j)) {
			ans += bit[j];
		}
		for (int j = a+1; j <= int(vals.size()); j += (j & -j)) {
			bit[j]++;
		}
	}
	cout << ans << '\n';

	return 0;
}
