#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, res, k, a[N];
vector <int> ad[N];

int dfs(int v, int d) {
	int mx = d;
	for (auto u: ad[v]) {
		int t = dfs(u, d + 1);
		if (t - d == k) {
			if (v == 1)
				continue;
			res++;
			t = d;
		}
		mx = max(mx, t);
	}
	return mx;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1) {
			if (a[i] != 1)
				a[i] = 1, res++;
		}
		else
			ad[a[i]].push_back(i);
	}
	dfs(1, 0);
	cout << res;
	return 0;
}
