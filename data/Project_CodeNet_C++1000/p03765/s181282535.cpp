#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	auto tapu = [&](string a, vector<vector<int>>& d) -> void {
		for (int i = 0; i < a.size(); ++i) {
			(a[i] == 'A' ? d[i+1][0] : d[i+1][1]) += 1;
			d[i+1][0] += d[i][0];
			d[i+1][1] += d[i][1];
		}
	};
	vector<vector<int>> ds(s.size() + 1, vector<int>(2, 0));
	vector<vector<int>> dt(s.size() + 1, vector<int>(2, 0));
	tapu(s, ds);
	tapu(t, dt);

	int Q;
	cin >> Q;
	vector<bool> ans(Q);
	for (int q = 0; q < Q; ++q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sumS = (ds[b][0] - ds[a-1][0]) * 2 + (ds[b][1] - ds[a-1][1]);
		int sumT = (dt[d][0] - dt[c-1][0]) * 2 + (dt[d][1] - dt[c-1][1]);
		ans[q] = sumS % 3 == sumT % 3;
	}
	for (auto v : ans) { cout << (v ? "YES" : "NO") << endl; }

	return 0;
}
