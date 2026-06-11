#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt = 0;
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt++;
		if (cnt * 2 > x + 1) {
			(ans *= cnt) %= MOD;
			cnt--;
		}
	}

	for (int i = 2; i <= cnt; i++) {
		(ans *= i) %= MOD;
	}
	cout << ans << endl;
	return 0;
}