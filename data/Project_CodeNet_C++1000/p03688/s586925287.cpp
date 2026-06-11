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

void yes() {
	cout << "Yes" << endl;
	exit(0);
}

void no() {
	cout << "No" << endl;
	exit(0);
}

const int N = 1e5 + 5;
int a[N];

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	if(s.size() > 2) {
		no();
		return;
	}
	if(s.size() == 1) {
		int v = *s.begin();
		if(v == n - 1) {
			yes();
		}
		if(2 * v <= n) {
			yes();
		}
		no();
	}
	int v1 = *s.begin();
	s.erase(s.begin());
	int v2 = *s.begin();
	if(v2 != v1 + 1) {
		no();
	}
	int c1 = 0, c2 = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == v1) c1++;
		else c2++;
	}
	if(v2 > c1 && 2 * (v2 - c1) + c1 <= n) {
		yes();
	}
	no();
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