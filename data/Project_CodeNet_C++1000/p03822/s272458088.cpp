#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int dfs(int s, vector<vector<int>>& g) {
	map<int, int> mp;
	for (int t : g[s]) {
		mp[dfs(t, g)]++;
	}
	int ret = 1;
	for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
		ret = max(ret, itr->first);
		ret += itr->second;
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

	int ans = dfs(0, g) - 1;
	cout << ans << endl;

	return 0;
}
