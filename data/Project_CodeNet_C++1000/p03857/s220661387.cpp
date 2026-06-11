
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

int grp[2][200003];
vector<int> edge[2][200003];
int ans[200003];
vector<pair<pair<int, int>, int>> t;

void func(int s, int pos, int g) {
	grp[s][pos] = g;
	for (int i = 0; i < (int)edge[s][pos].size(); ++i) {
		if (grp[s][edge[s][pos][i]] != 0) continue;
		func(s, edge[s][pos][i], g);
	}
}


int main() {
	int n, k, l; cin >> n >> k >> l;
	for (int i = 0; i < k; ++i) {
		int u, v; cin >> u >> v;
		--u; --v;
		edge[0][u].push_back(v);
		edge[0][v].push_back(u);
	}
	for (int i = 0; i < l; ++i) {
		int u, v; cin >> u >> v;
		--u; --v;
		edge[1][u].push_back(v);
		edge[1][v].push_back(u);
	}
	for (int s = 0; s < 2; ++s) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (grp[s][i] != 0) continue;
			func(s, i, ++cnt);
		}
	}

	for (int i = 0; i < n; ++i) t.push_back({ {grp[0][i], grp[1][i] }, i });
	sort(t.begin(), t.end());

	int g = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = i; j < n; ++j) {
			if (t[i].first.first == t[j].first.first && t[i].first.second == t[j].first.second) ++cnt;
			else break;
		}
		for (int j = i; j < n; ++j) {
			if (t[i].first.first == t[j].first.first && t[i].first.second == t[j].first.second) ans[t[j].second] = cnt;
			else break;
		}
		i += cnt - 1;
		++g;
	}

	for (int i = 0; i < n; ++i) {
		if (i > 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}