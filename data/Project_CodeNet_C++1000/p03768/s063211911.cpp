#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

vector<int> ans;
vector<set<int>> visited;
vector<vector<int>> adj;

void solve(int v, int d, int c) {
	if (visited[v].find(d) == visited[v].end()) {
		visited[v].insert(d);
		if (d == 0) ans[v] = c;
		else {
			solve(v, d - 1, c);
			for (auto p : adj[v]) {
				solve(p, d - 1, c);
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, q, i, j, k, a, b, v, d, c;
	cin >> n >> m;

	adj.resize(n + 1);
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> q;
	vector<tuple<int, int, int>> query(q);
	for (i = 0; i < q; i++) {
		cin >> v >> d >> c;
		query[i] = make_tuple(v, d, c);
	}

	ans.assign(n + 1, 0);
	visited.resize(n + 1);

	for (i = q - 1; i >= 0; i--) {
		tie(v, d, c) = query[i];
		solve(v, d, c);
	}

	for (i = 1; i <= n; i++) cout << ans[i] << "\n";		

	return 0;
}
