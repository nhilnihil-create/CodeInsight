#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, x;
ll ans = 0;

main() {
	cin >> n >> x;
	if (x * 2 >= n) x = n - x;
	ans = n;
	n -= x;
	while (x) {
		ans += (2 * x * (n / x));
		ll temp = x;
		if (n % x == 0) ans -= x;
		x = n % x;
		n = temp;
	}
	cout << ans;
}
