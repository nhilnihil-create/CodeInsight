#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 100100;

int n, k, ans, par[N];
vector<int> g[N];

int dfs(int v, int p = -1) {
	int res = 0;
	for (int to: g[v]) 
		res = max(res, dfs(to, v));
	if (res == k - 1 && par[v] != 1) {
		ans++;
		return 0;
	}
	return res + 1;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
		if (i != 1) g[par[i]].pb(i);
		else {
			ans += par[i] != 1;
			par[i] = 1;
		}
	}
	dfs(1);
	cout << ans;
}
