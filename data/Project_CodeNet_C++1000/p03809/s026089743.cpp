#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#define N 100005

vector<int> adj[N];

int a[N], dp[N];

bool dfs(int node, int p) {
	if (adj[node].size() == 1) {
		dp[node] = a[node];
		return true;
	}
	int maxi = 0;
	long long sum = 0;
	int sz = adj[node].size();
	for (int i = 0; i < sz; ++i) {
		int ch = adj[node][i];
		if (ch == p) {
			continue;
		}
		if (!dfs(ch, node)) {
			return false;
		}
		sum += dp[ch];
		maxi = max(maxi, dp[ch]);
	}
	long long k = sum - a[node];
	if (k<0 || k>a[node] || k > sum || sum - maxi < k) {
		return false;
	}
	dp[node] = a[node] - k;
	return true;
}
void solve() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	if (n == 2) {
		if (a[1] == a[2]) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		return;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() > 1) {
			root = i;
			break;
		}
	}
	if (!dfs(root, 0) || dp[root] != 0) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
