#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 1e9 + 7;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}

int n, m;
const int N = 1e5 + 5;
int cnt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		cnt[u] ^= 1, cnt[v] ^= 1;
	}
	if(*(max_element(cnt + 1, cnt + n + 1)) == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	for(int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}