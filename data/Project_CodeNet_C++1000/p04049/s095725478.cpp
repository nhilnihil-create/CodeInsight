#include <bits/stdc++.h>
using namespace std;

int n, k;
vector <int> from[2010];
int deep[2010];

void dfs(int x, int last){
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		if (v == last) continue;
		deep[v] = deep[x] + 1, dfs(v, x);
	}
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	if (k & 1){
		int ans = 0x3f3f3f3f;
		for (int u = 1; u <= n; u++){
			for (int i = 0; i < from[u].size(); i++){
				int v = from[u][i];
				deep[u] = deep[v] = 0;
				dfs(u, v), dfs(v, u);
				int cnt = 0;
				for (int j = 1; j <= n; j++){
					cnt += deep[j] > (k - 1) / 2;
				}
				ans = min(ans, cnt);
			}
		}
		printf("%d\n", ans);
		return 0;
	} else {
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++){
			deep[i] = 0, dfs(i, i);
			int cnt = 0;
			for (int j = 1; j <= n; j++){
				cnt += deep[j] > k / 2;
			}
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
		return 0;
	}
	return 0;
}
