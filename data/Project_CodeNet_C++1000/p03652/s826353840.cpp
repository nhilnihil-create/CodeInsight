#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n+1, vector<int>(m+1));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> v[i][j];
		}
	}
	

	vector<bool> pres(m+1, true);
	vector<int> cnt(m+1);
	int ans = n;

	for(int i = 1; i <= m + 2; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				if(pres[v[j][k]]) {
					cnt[v[j][k]]++;
					break;
				}
			}
		}

		int mx = 0;
		for(int j = 1; j <= m; j++) {
			mx = max(mx, cnt[j]);
		}

		ans = min(ans, mx);
		for(int j = 1; j <= m; j++) {
			if(cnt[j] == mx) pres[j] = false;
			cnt[j] = 0;
		}

		bool flag = false;

		for(int j = 1; j <= m; j++) {
			if(pres[j]) flag = true;
		}

		if(!flag) break;
	}

	cout << ans;

	return 0;
}