#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int bb[1234][1234], cc[123][123][123];
int res[123456], uio[1234][1234];
signed main() {
	int n, m, a, b, x = INF, mae = 0, ans = 0; cin >> n >> m;
	for (int h = 0; h < n; h++) {
		cin >> a;
		if (h > 0 && (a + mae) >= m) { x = h; }
		mae = a;
	}
	if (x == INF) { cout << "Impossible" << endl; return 0; }
	cout << "Possible" << endl;
	for (int h = 1; h < x; h++) {
		cout << h << endl;
	}
	for (int h = n - 1; h > x; h--) {
		cout << h << endl;
	}
	cout << x << endl;
	return 0;
}