#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int N = 1e5 + 7;

int fl = 0;
int used[N];
int c[N];
vector<int> g[N];

void dfs(int cur, int cl) {
	used[cur] = 1;
	c[cur] = cl;
	for (auto t : g[cur]) {
		if (!used[t]) {
			dfs(t, cl ^ 1);
		} else if (c[cur] == c[t]) {
			fl = 1;
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int cnt_all = 0;
	int cnt_c = 0;
	int cnt_1 = 0;
	for (int i = 0; i < n; i++) {
		if (g[i].empty()) {
			cnt_1++;
		} else if (!used[i]){
			fl = 0;
			dfs(i, 0);
			if (!fl) cnt_c++;
			cnt_all++;
		}
	}
	cout << (cnt_all) * (cnt_all) + (cnt_c) * (cnt_c) + 2 * cnt_1 * (n - cnt_1) + cnt_1 * cnt_1 << endl;
}