#include <bits/stdc++.h>

#define int long long

using namespace std;

int ans[200001];
vector <int> g[200001];
int n,  k;
int u[200001];
int mx;
int d[200001];
int a[200001];

void dfs (int v) {
	u[v] = 1;
	for (auto to : g[v]) {
		if (u[to]) continue;
		dfs (to);
		ans[v] += ans[to];
		d[v] = max (d[v], d[to] + 1);
	}
	if (d[v] >= k - 1 && a[v] != 1) {       
		ans[v] ++;
		d[v] = -1;
	}
}

 main () {
    ios_base::sync_with_stdio (0);
    cin.tie (0), cout.tie (0);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) {
		int x;
		cin >> x;
		a[i] = x;
		a[1] = 1;
		if (i == 1) {
			if (x != 1) ans[1] = 1;
		}
		else g[x].push_back (i);
	}
	dfs (1);
	cout << ans[1];
	return 0;
}