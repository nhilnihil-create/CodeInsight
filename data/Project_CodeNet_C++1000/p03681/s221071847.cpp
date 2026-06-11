#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, m;
	cin >> n >> m;
	if (abs(n - m) >= 2) {
		cout << 0 << endl;
		return 0;
	}
	if (n > m)swap(n, m);
	ll ans = 1;
	if (n == m) {
		ans = 2;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= 1000000007;
			ans *= i;
			ans %= 1000000007;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= 1000000007;
			ans *= i;
			ans %= 1000000007;
		}
		ans *= m;
		ans %= 1000000007;
	}
	cout << ans << endl;
}