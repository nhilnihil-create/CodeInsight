#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int go[17][N];

int main() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int L; cin >> L;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j < n && a[j + 1] - a[i] <= L) j++;
		go[0][i] = j;
	}
	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= n; j++) {
			go[i][j] = go[i - 1][go[i - 1][j]];
		}
	}
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		int ans = 0;
		for (int i = 16; i >= 0; i--) {
			if (go[i][u] >= v) continue;
			u = go[i][u];
			ans |= 1 << i;
		}
		ans++;
		cout << ans << "\n";
	}
	return 0;
}