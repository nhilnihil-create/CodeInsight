#include <bits/stdc++.h>

#define int long long

using namespace std;

int a[100001];
vector <int> g[100001];
int d[100001];
int c[100001];
int ans[100001];
int was[100001];
int u[100001];
int timer;

void dfs (int v, int k, int col) {
	queue <pair <int, int> > q;
	q.push (make_pair (k, v));
//	cout << "NEW\n";
	while (!q.empty ()) {
		pair <int, int> qwe = q.front ();
		int len = qwe.first;
		int v = qwe.second;
		q.pop ();
//		cout << v << ' ' << len << endl;
		was[v] = max (len, was[v]);
		if (!ans[v]) ans[v] = col;
		for (auto to : g[v]) {
			if (was[to] < len - 1) {
				q.push (make_pair (len - 1, to));
			}	
		}
	}
}

 main () {
	int n;
	int m;
	cin >> n >> m;
	for (int i = 1;i <= m;i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}
	for (int i = 1;i <= n;i ++) was[i] = -1;
	int q;
	cin >> q;
	for (int i = 1;i <= q;i ++) {
		cin >> a[i] >> d[i] >> c[i];
	}
	for (int i = q;i >= 1;i --) {
		timer ++;
		dfs (a[i], d[i], c[i]);
	}
	for (int i = 1;i <= n;i ++) cout << ans[i] << endl;
	return 0;
}