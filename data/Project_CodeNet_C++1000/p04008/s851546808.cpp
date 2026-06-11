#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 100010;
struct node{
	int pre, to;
}edge[N << 1];
int head[N], tot;
int n, k;
int a[N];
int dis[N], mx[N];
int ans;
bool vis[N];
void dfs(int x) {
	for (int i = head[x]; i; i = edge[i].pre) {
		int y = edge[i].to;
		dis[y] = dis[x] + 1;
		dfs(y);
		mx[x] = max(mx[x], mx[y]);
	}
	mx[x] = max(mx[x], dis[x]);
	if (x != 1) {
		if (mx[x] - dis[x] >= k) mx[x] = 0, ans++;
		if (mx[x] - dis[x] == k - 1 && a[x] != 1) mx[x] = 0, ans++;
	}
}
void add(int u, int v) {
	edge[++tot] = node{head[u], v};
	head[u] = tot;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (i == 1) {
			if (a[i] != 1) ans++;
		} else {
			add(a[i], i);
		}
	}
	dfs(1);
	cout << ans;
	return 0;
}