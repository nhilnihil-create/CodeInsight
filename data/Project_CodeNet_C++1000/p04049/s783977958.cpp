#include <iostream>
#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable:4996)
const int maxn = 2005;
vector<int> E[maxn];
int vis[maxn], k, cnt, u[maxn], v[maxn];
void dfs(int x, int step) {
	if (step == k + 1)
		return;
	for (int i = 0; i < E[x].size(); i++) {
		if (vis[E[x][i]] == -1) {
			vis[E[x][i]] = step;
			cnt++;
			dfs(E[x][i], step + 1);
		}
		else if (vis[E[x][i]] > step) {
			vis[E[x][i]] = step;
			dfs(E[x][i], step + 1);
		}
	}
}
int main() {
	int n;
	scanf("%d%d", &n, &k);
	int ans = n;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u[i], &v[i]);
		E[u[i]].push_back(v[i]);
		E[v[i]].push_back(u[i]);
	}
	if (~k & 1) {
		k >>= 1;
		for (int i = 1; i <= n; i++) {
			fill(vis, vis + n + 1, -1);
			vis[i] = 0; cnt = 1;
			dfs(i, 1);
			ans = min(ans, n - cnt);
		}
	}
	else {
		k >>= 1;
		for (int i = 1; i < n; i++) {
			fill(vis, vis + n + 1, -1);
			vis[u[i]] = vis[v[i]] = 0; cnt = 2;
			dfs(u[i], 1); dfs(v[i], 1);
			ans = min(ans, n - cnt);
		}
	}
	printf("%d\n", ans);
}