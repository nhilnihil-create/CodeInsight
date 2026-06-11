#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, p;
	cin >> n >> p;
	int odd = 0, even = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2 == 0) even += 1;
		else odd += 1;
	}
	if (odd > 0) cout << (1ll << (odd - 1)) * (1ll << even);
	else cout << (p == 0 ? (1ll << even) : 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}