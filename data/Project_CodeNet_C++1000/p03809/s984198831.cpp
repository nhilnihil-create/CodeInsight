#include <bits/stdc++.h>
 
using namespace std;
 
int a[100001];
vector <int> g[100001];
int st = 1;

int dfs (int v, int pr) {
	int cost = a[v] + a[v];
	if (g[v].size () == 1 && v != st) {
		return a[v];
	}
	if (g[v].size () == 1) cost = a[v];
	int mx = 0;
	for (auto to : g[v]) {
		if (to == pr) continue;
		int len = dfs (to, v);
		cost -= len; 
		mx = max (mx, len);
	}        
	if (v == st && cost > 0) {
		cout << "NO";
		exit (0);
	}
	if (cost < 0) {
		cout << "NO";
		exit (0);
	}
	mx = max (mx, cost);
	if (mx > a[v]) {
		cout << "NO";
		exit (0);
	}
	return cost;
}

int main () {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a[i];
	for (int i = 1;i < n;i ++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back (y);
		g[y].push_back (x);
	}
	for (int i = 1;i <= n;i ++) {
		if (g[i].size () > 1) {
			st = i;
			break;
		}
	}   
	dfs (st, 0);
	cout << "YES";
	return 0;
}