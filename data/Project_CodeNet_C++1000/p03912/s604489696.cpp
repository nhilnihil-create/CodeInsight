#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int memo[100010] = {};
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		memo[x]++;
	}

	vector< vector<int> > a(m);
	for (int i = 1; i <= 100000; i++) {
		if (memo[i] == 0) continue;
		a[i % m].emplace_back(memo[i]);
	}
    
	vector<int> sum(m);
	for (int i = 0; i < m; i++) {
        sum[i] = accumulate(a[i].begin(), a[i].end(), 0);
	}

	int ans = sum[0] / 2;
	if (m % 2 == 1) {
		for (int i = 1; i <= m / 2; i++) {
			int tmp = 0;
			if (sum[i] < sum[m - i]) {
				swap(a[i], a[m - i]);
				swap(sum[i], sum[m - i]);
			}
			ans += sum[m - i];
			for (int j = 0; j < (int)a[i].size(); j++) {
				tmp += a[i][j] / 2;
				a[i][j] %= 2;
			}
			ans += min(tmp, (sum[i] - sum[m - i]) / 2);
		}
	} else {
		for (int i = 1; i < m / 2; i++) {
			int tmp = 0;
			if (sum[i] < sum[m - i]) {
				swap(a[i], a[m - i]);
				swap(sum[i], sum[m - i]);
			}
			ans += sum[m - i];
			for (int j = 0; j < (int)a[i].size(); j++) {
				tmp += a[i][j] / 2;
				a[i][j] %= 2;
			}
			ans += min(tmp, (sum[i] - sum[m - i]) / 2);
		}
		ans += sum[m / 2] / 2;
	}
	cout << ans << endl;
	return 0;
}