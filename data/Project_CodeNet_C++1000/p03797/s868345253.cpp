#include <bits/stdc++.h>
using namespace std;
using ll = long long;
enum { };

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, m, ans = 0; cin >> n >> m;
	if (n >= m/2) {
		ans = m/2;
	} else {
		ans = n + (m - 2*n)/4;
	}
	cout << ans << endl;
	return 0;
}
