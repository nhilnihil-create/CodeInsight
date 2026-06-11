#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;

int solve(int s = 0, int p = -1) {
	vector<int> v_c;
	for (int c : g[s])
		if (c != p)
			v_c.push_back(solve(c, s));
	sort(v_c.begin(), v_c.end());
	reverse(v_c.begin(), v_c.end());
	int res = 0;
	for (int i = 0; i < v_c.size(); ++i)
		res = max(res, v_c[i] + i + 1);
	return res;
}

int main() {
	cin >> n;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int a; cin >> a;
		--a;
		g[a].push_back(i);
		g[i].push_back(a);
	}
	cout << solve() << endl;
	return 0;
}