#include <bits/stdc++.h>

const int kN = 2e3 + 5;
const int kInf = 0x3f3f3f3f;

bool vis[kN]; std::vector<int> E[kN];
int k, n, ans = kInf;
void Dfs(int cur, int d) {
	if(d > k / 2) return;
	vis[cur] = true;
	for(int x : E[cur])
		if(!vis[x]) Dfs(x, d + 1);
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		E[x].push_back(y); E[y].push_back(x);
	}
	if(k & 1) {
		for(int i = 1; i <= n; ++i) for(int x : E[i]) if(x < i) {
			memset(vis, false, sizeof(vis));
			int tot = 0;
			vis[x] = true; Dfs(i, 0); Dfs(x, 0);
			for(int j = 1; j <= n; ++j)
				if(!vis[j]) ++tot;
			ans = std::min(ans, tot);
		}
	} else {
		for(int i = 1; i <= n; ++i) {
			memset(vis, false, sizeof(vis));
			int tot = 0;
			Dfs(i, 0);
			for(int j = 1; j <= n; ++j)
				if(!vis[j]) ++tot;
			ans = std::min(ans, tot);
		}
	}
	printf("%d", ans);
	return 0;
}