#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, k, a[maxn + 10], ans;
vector<int> g[maxn + 10];

int dfs(int p, int dep) {
	int mx = 0;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		mx = max(mx, dfs(e, dep + 1) + 1);
	}
	if (mx == k - 1 && dep > 1) {
		++ans; mx = -1;
	}
	return mx;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if (a[1] != 1) {
		a[1] = 1; ++ans;
	}
	if (k == 1) {
		for (int i = 2; i <= n; ++i)
			if (a[i] != 1) ++ans;
		printf("%d", ans);
		return 0;
	}
	for (int i = 2; i <= n; ++i) g[a[i]].push_back(i);
	dfs(1, 0);
	printf("%d", ans);
}
