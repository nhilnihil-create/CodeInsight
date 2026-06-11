#include <bits/stdc++.h>
using namespace std;
using ll = long long;
enum { M = 1000000007, N = 1100 };
vector<bool> p(N + 5, true);

void init() {
	p[0] = false;
	p[1] = false;
	for (ll i = 2; i <= N; i++) {
		if (p[i]) {
			for (ll k = 2; k*i <= N; k++) {
				p[k*i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	init();
	ll n, ans = 1; cin >> n;
	for (ll i = 1; i <= n; i++) {
		if (p[i]) {
			ll temp = 0, check = i;
			while (n/check > 0) {
				temp += n/check;
				check = check * i;
			}
			ans = (ans * (temp + 1)) % M;
		}
	}
	cout << ans << "\n";
	return 0;
}