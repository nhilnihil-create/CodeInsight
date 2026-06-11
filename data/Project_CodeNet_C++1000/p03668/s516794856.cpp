#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;

void input() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
}

int grundy(int s = 0, int p = -1) {
	int res = 0;
	for (auto c : g[s]) {
		if (c != p) {
			int tmp = grundy(c, s);
			res ^= (tmp + 1);
		}
	}
	return res;
}

int main() {
	input();
	cout << (grundy() ? "Alice" : "Bob") << endl;
	return 0;
}