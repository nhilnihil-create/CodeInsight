#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n, m, co[maxn + 10], cnt[2], tot;
vector<int> g[maxn + 10];

bool dfs(int p) {
	bool fd = 0;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (!co[e]) {
			co[e] = 3 - co[p]; fd |= dfs(e);
		} else if (co[p] == co[e]) fd = 1;
	}
	return fd;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r);
		g[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i)
		if (!co[i]) {
			if ((int)g[i].size() > 0) {
				co[i] = 1;
				++cnt[dfs(i)];
			} else ++tot;
		}
	printf("%lld", 1ll * tot * tot + 2ll * (n - tot) * tot + 1ll * cnt[0] * cnt[0]  + 1ll * (cnt[0] + cnt[1]) * (cnt[0] + cnt[1]));
}
