#include <bits/stdc++.h>
using namespace std;
vector<int> a[200500];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	bool ok = false;
	for (auto f : a[1]) {
		if (f == n) {
			ok = true;
		}
		for (auto ff : a[f]) {
			if (ff == n) {
				ok = true;
			}
		}
	}
	if (ok)
		cout << "POSSIBLE";
	else
		cout << "IMPOSSIBLE";
	return 0;
}