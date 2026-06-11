#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, t, c[N], mdis[N], dis[N], mark[N];
vector<int> gr[N];
vector<pair<int, pair<int, int> > > q;
void bfs(int st, int d, int cl) {
	vector<int> vr;
	queue<int> q;
	if (mdis[st] < d)
		q.push(st), mark[st] = 1, dis[st] = d;
	while (!q.empty()) {
		int v = q.front();
		vr.push_back(v);
		q.pop();
		for (auto u : gr[v])
			if (!mark[u] && mdis[u] < dis[v] - 1)
				mark[u] = 1, dis[u] = dis[v] - 1, q.push(u);
	}	
	for (auto u : vr) {
		mdis[u] = dis[u];
		dis[u] = mark[u] = 0;
		if (c[u] == 0)
			c[u] = cl;
	}
	return;
}
int main() {
	memset(mdis, -1, sizeof(mdis));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		int vv, dd, cc;
		cin >> vv >> dd >> cc;
		vv--;
		q.push_back({vv, {dd, cc}});
	}
	reverse(q.begin(), q.end());
	for (int i = 0; i < t; i++)
		bfs(q[i].first, q[i].second.first, q[i].second.second);
	for (int i = 0; i < n; i++) 
		cout << c[i] << endl;
	return 0;
}
