#include <cstdio>
#include <algorithm>
const int MAXN = 1e5 + 5, MAXM = 30;
long long a[MAXN], k;
int d[MAXN], index[MAXN], T[MAXN], n, m;
int new_pos[MAXN][MAXM];
bool vis[MAXN];
int dfs(int i, int cnt_edge) {
	if(vis[i]) return cnt_edge;
	vis[i] = true;
	return T[i] = dfs(new_pos[i][0], cnt_edge + 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), index[i] = i;
	scanf("%d%lld", &m, &k);
	for(int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		std::swap(index[x], index[x - 1]);
	}
	for(int i = 1; i <= n - 1; i++) new_pos[index[i]][0] = i;
	for(int i = 1; i <= n - 1; i++) if(!vis[i]) dfs(i, 0);
	for(int j = 1; j < MAXM; j++) {
		for(int i = 1; i <= n - 1; i++) new_pos[i][j] = new_pos[new_pos[i][j - 1]][j - 1];
	}
	for(int i = 1; i <= n - 1; i++) {
		int cur = k % T[i], pos = i;
		for(int j = 0; cur != 0; cur >>= 1, j++) {
			if(cur & 1) pos = new_pos[pos][j];
		}
		index[pos] = i;
	}
	double cur = a[1];
	for(int i = 1; i <= n; i++) {
		printf("%.1f\n", cur);
		cur += a[index[i] + 1] - a[index[i]];
	}
	return 0;
}
