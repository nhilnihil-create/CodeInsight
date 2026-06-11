#include <bits/stdc++.h>
using namespace std;



int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, x, y; cin >> n >> k >> x >> y;
	int ans = min(n, k) * x;
	n -= min(n, k);
	ans += n * y;
	cout << ans << endl;
}