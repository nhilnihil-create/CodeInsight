#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second
#define pb push_back

const int inf = 2e9;
const int N = 2010;

int n, k;
vector<int> g[N];
pii edges[N];

void dfs(int v, int &res, int p = -1, int d = 0) {
	if (d > k / 2) res++;
	for (int to: g[v])
		if (to != p) dfs(to, res, v, d + 1);
}

int get(int x) {
	int res = 0;
	dfs(x, res);
	return res;
}

int getEdge(int x) {
	int res = 0;
	dfs(edges[x].F, res, edges[x].S);
	dfs(edges[x].S, res, edges[x].F);
	return res;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		edges[i] = {a, b};
		g[a].pb(b);
		g[b].pb(a);
	}	
	int ans = inf;
	if (k % 2 == 0) {
		for (int i = 1; i <= n; i++)
			ans = min(ans, get(i));
	} else {
		for (int i = 1; i < n; i++)
			ans = min(ans, getEdge(i));
	}
	cout << ans;
}
