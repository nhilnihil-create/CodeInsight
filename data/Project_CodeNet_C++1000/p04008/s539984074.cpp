#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 5, inf = 1e9 + 7;
int n, k, ans;
bool mark[MAX_N];
int nxt[MAX_N];
int dis[MAX_N];
vector <int> topo;
vector <int> child[MAX_N];

void dfs (int v) {
	mark[v] = true;
	if (!mark[nxt[v]])
		dfs(nxt[v]);

	topo.push_back(v);
}

int dfs2 (int v = 0) {
	int tmp = dis[v];
	for (int u: child[v])
		tmp = max(tmp, dfs2(u));


	if (!v)
		return 0;

	if (tmp - dis[v] == k - 1 && nxt[v]) {
		ans++;
		nxt[v] = 0;
		dis[v] = 1;
		return -inf;
	}

	return tmp;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> nxt[i];
		nxt[i]--;

		if (i) {
			child[nxt[i]].push_back(i);
			cnt += nxt[i] != 0;
		}
	}
	if (nxt[0] != 0) {
		ans++;
		nxt[0] = 0;
	}

	if (k == 1) {
		ans += cnt;
		cout << ans << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i);

	for (int v: topo)
		dis[v] = 1 + dis[nxt[v]];


	dfs2();
	cout << ans << "\n";
	return 0;
}