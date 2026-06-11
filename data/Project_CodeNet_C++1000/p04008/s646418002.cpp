#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;

int n, k, ans = 0, fa[kN], dep[kN];
std::vector<int> ch[kN];
std::priority_queue<pii> que;
bool vis[kN];

void Dfs(int x) {
	dep[x] = dep[fa[x]] + 1;
	for(int i : ch[x]) Dfs(i);
}
void Fill(int x, int d) {
	vis[x] = true;
	if(!d) return;
	for(int i : ch[x]) Fill(i, d - 1);
}

int main() {
	scanf("%d%d%d", &n, &k, fa + 1);
	if(fa[1] != 1) ++ans, fa[1] = 1;
	for(int i = 2; i <= n; ++i) {
		scanf("%d", fa + i);
		ch[fa[i]].push_back(i);
	}
	Dfs(1); Fill(1, k);
	for(int i = 1; i <= n; ++i)
		if(!ch[i].size() && !vis[i]) que.push(std::make_pair(dep[i], i));
	while(!que.empty()) {
		int v = que.top().second; que.pop();
		if(vis[v]) continue;
		for(int i = 1; i < k; ++i) v = fa[v];
		Fill(v, k - 1); ++ans;
		if(fa[v] != 1) que.push(std::make_pair(dep[fa[v]], fa[v]));
	}
	printf("%d", ans);
	return 0;
}