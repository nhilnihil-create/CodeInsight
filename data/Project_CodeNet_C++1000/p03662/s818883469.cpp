#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> g;

void input() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

vector<int> path;

tuple<bool, int> dfs(int s = 0, int p = -1) {
	int cnt_children = 0;
	int rem = 0;
	bool is_path = false;
	if (s == n - 1) is_path = true;
	for (auto c : g[s]) {
		if (c != p) {
			tuple<bool, int> tmp = dfs(c, s);
			is_path |= get<0>(tmp);
			cnt_children += get<1>(tmp) + 1;
			if (get<0>(tmp)) rem = get<1>(tmp) + 1;
		}
	}
	if (is_path)
		path.push_back(cnt_children + 1 - rem);
	return make_tuple(is_path, cnt_children);
}

int main() {
	input();
	dfs();
	reverse(path.begin(), path.end());
	int f_ptr = 0, s_ptr = path.size() - 1;
	int cnt_f = 0, cnt_s = 0;
	while (f_ptr <= s_ptr) {
		cnt_f += path[f_ptr++];
		if (s_ptr >= f_ptr)
			cnt_s += path[s_ptr--];
	}
	if (cnt_f > cnt_s)
		cout << "Fennec" << endl;
	else
		cout << "Snuke" << endl;
	return 0;
}
