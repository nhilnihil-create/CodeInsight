#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

void solve() {
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (m - n > 1) cout << 0;
	else {
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			if (ans >= MOD) {
				ans %= MOD;
			}
		}

		for (int i = 1; i <= m; i++) {
			ans *= i;
			if (ans >= MOD) ans %= MOD;
		}
		if (n == m) ans *= 2;
		ans %= MOD;
		cout << ans;

	}	
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1; 
    //cin >> T;
    while(T--) solve();
}