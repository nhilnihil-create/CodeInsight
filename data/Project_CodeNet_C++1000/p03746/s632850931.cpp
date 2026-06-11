#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int st, n, m;
bool mark[N];
vector<int> gr[N], d[3];
void dfs(int v, int dr) {
	d[dr].push_back(v);
	mark[v] = 1;
	for (auto u : gr[v]) {
		if (!mark[u]) {
			dfs(u, dr);
			break;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(0, 0);
	dfs(0, 1);
	cout << (int) d[0].size() + (int) d[1].size() - 1 << endl;
	for (int i = (int) d[0].size() - 1; i >= 0; i--) {
		cout << d[0][i] + 1 << " ";
	}
	for (int i = 1; i < d[1].size(); i++)
		cout << d[1][i] + 1 << " ";
	return 0;
}
