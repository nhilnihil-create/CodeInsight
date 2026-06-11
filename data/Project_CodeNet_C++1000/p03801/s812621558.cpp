#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Int> a(N);
	map<Int, vector<int>> mp;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		mp[a[i]].emplace_back(i);
	}

	sort(a.rbegin(), a.rend());
	a.erase(unique(a.begin(), a.end()), a.end());

	vector<Int> ans(N, 0);
	int idx = 1e9;
	for (auto val : mp[a[0]]) { idx = min(idx, val); }
	Int sum = mp[a[0]].size();
	a.emplace_back(0);
	mp[0].emplace_back(-1);
	for (int i = 0; i + 1 < a.size(); ++i) {
		ans[idx] += sum * (a[i] - a[i + 1]);
		sum += mp[a[i + 1]].size();
		for (auto val : mp[a[i + 1]]) { idx = min(idx, val); }
	}
	for (auto v : ans) { cout << v << endl; }

	return 0;
}
