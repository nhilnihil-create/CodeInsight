#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
			--a[i][j];
		}
	}
	bool open[m];
	for(int i = 0; i < m; ++i) open[i] = true;
	int ans = n;
	for(int q = 0; q < m - 1; ++q) {
		int cnt[m] = {};
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(open[a[i][j]]) {
					++cnt[a[i][j]];
					break;
				}
			}
		}
		int maxi = 0, midx;
		for(int i = 0; i < m; ++i) {
			if(maxi < cnt[i]) {
				maxi = cnt[i];
				midx = i;
			}
		}
		ans = min(ans, maxi);
		open[midx] = false;
	}
	cout << ans << '\n';
	return 0;
}