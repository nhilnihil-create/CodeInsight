#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n, m;
vector<int> E[MAXN];
int color[MAXN];

void DFS(int u, bool &flag){
	for (auto v: E[u])
		if (~color[v])
			flag |= color[u] == color[v];
		else{
			color[v] = !color[u];
			DFS(v, flag);
		}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	ll cnt[3] = {0, 0, 0};
	fill_n(color + 1, n, -1);
	for (int i = 1; i <= n; ++i)
		if (E[i].size() == 0)
			++cnt[0];
		else if (!~color[i]){
			bool flag = false;
			color[i] = 0;
			DFS(i, flag);
			++cnt[1 + flag];
		}
	printf("%lld\n", (cnt[1] + cnt[2]) * (cnt[1] + cnt[2]) + cnt[1] * cnt[1] + cnt[0] * n * 2 - cnt[0] * cnt[0]);
	return 0;
}
