#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (a[j][k] != min(a[j][k], a[j][i] + a[i][k])) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool ok = true;
			for (int k = 0; k < n; k++) {
				if (i == k || j == k) continue;
				if (a[i][j] == a[i][k] + a[k][j]) ok = false;
			}
			if (ok) ans += a[i][j];
		}
	}
	cout << ans << '\n';
	return 0;		
}
