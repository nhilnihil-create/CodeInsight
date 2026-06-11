#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, m; cin >> n >> m;
	ll ans = 0;
	if (2 * n <= m) {
		ans += n;
		m -= 2 * n;
		ans += m / 4;
	}
	else { // m < 2 * n
		ans = m / 2;
	}
	cout << ans << endl;
	return 0;
}