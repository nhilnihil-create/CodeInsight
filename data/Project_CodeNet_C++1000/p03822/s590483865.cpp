#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int dfs(int s, vector<vector<int>>& g) {
	vector<int> memo;
	for (int t : g[s]) {
		memo.emplace_back(dfs(t, g));
	}
	
	sort(memo.rbegin(), memo.rend());
	int ret = 0;
	for (int i = 0; i < memo.size(); ++i) {
		ret = max(ret, i + 1 + memo[i]);
	}
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	vector<vector<int>> g(N);
	for (int i = 1; i < N; ++i) {
		cin >> a[i];
		--a[i];
		g[a[i]].emplace_back(i);
	}

	int ans = dfs(0, g);
	cout << ans << endl;

	return 0;
}
