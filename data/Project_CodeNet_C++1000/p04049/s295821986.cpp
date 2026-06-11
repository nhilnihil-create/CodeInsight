#include <cstdio>
#include <vector>

std::vector<int> E[2048];
int s;
void dfs(int x, int f, int d) {
	s++;
	if (d--) for (int y : E[x])
		if (y != f) dfs(y,x,d);
}

int main() {
	int n, k, ans = 0;
	scanf("%d%d",&n,&k);
	for (int i = n, u, v; --i;) {
		scanf("%d%d",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	if (k & 1) {
		k >>= 1;
		for (int x = 1; x <= n; x++)
			for (int y : E[x]) if (x < y) {
				s = 0;
				dfs(x,y,k);
				dfs(y,x,k);
				if (s > ans) ans = s;
			}
	} else {
		k >>= 1;
		for (int x = 1; x <= n; x++) {
			dfs(x,s = 0,k);
			if (s > ans) ans = s;
		}
	}
	printf("%d\n",n - ans);
	return 0;
}