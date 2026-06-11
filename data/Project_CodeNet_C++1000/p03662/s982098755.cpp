#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <cmath>
#define ll long long
#define LINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
const int MAX = 1e5 + 10;
const ll MOD = 1e9 + 7;
int N, M, K, Q;
bool vis[MAX];
vector<int> path;
vector<int> g[MAX];

bool dfs(int u) {
	vis[u] = true;
	path.push_back(u);
	if (u == N) {
		return true;
	}
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (vis[v]) continue;
		if (dfs(v)) return true;
	}
	path.pop_back();
	return false;
}

void dfs2(int u, int &cnt) {
	vis[u] = true;
	cnt += 1;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (vis[v]) continue;
		dfs2(v, cnt);
	}
}

int main()
{
	int i, j, k, u, v;
	scanf("%d", &N);
	for (i = 0; i < N - 1; ++i) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	int len = path.size();
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < path.size(); ++i) vis[path[i]] = true;
	vector<int> vec;
	for (i = 1; i < path.size() - 1; ++i) {
		int cnt = 0;
		dfs2(path[i], cnt);
		vec.push_back(cnt);
	}
	int a, b;
	a = b = 0;
	dfs2(1, a);
	dfs2(N, b);
	len -= 2;
	for (i = 0; i < vec.size(); ++i) {
		if (i < (len + 1) / 2) a += vec[i];
		else b += vec[i];
	}

	b += len / 2;
	a += (len + 1) / 2;
	if (a > b) printf("Fennec");
	else printf("Snuke");
}