#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
vector <int> adjList[100005];
int s;

long long dfs(int u, int p) {
	long long sum = 0;
	long long maxval = 0;
	if (adjList[u].size() == 1) return a[u];
	for (int v : adjList[u]) {
		if (v == p) continue;
		long long cur = dfs(v, u);
		sum += cur;
		maxval = max(cur, maxval);
		if (cur < 0) return -1;
	}
	if (a[u] > sum || maxval > a[u]) return -1;
	return a[u] * 2 - sum;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	if (n == 2) {
		if (a[1] == a[2]) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (adjList[i].size() >= 2) s = i;
	}
	if (dfs(s, -1) == 0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
