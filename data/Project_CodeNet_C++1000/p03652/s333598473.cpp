#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
#define fi first
#define se second
typedef pair<int, int> pii;

int n, m, a[310][310], cnt[310], now[310], vis[310];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= n; ++ i) {
		++ cnt[a[i][1]];
		now[i] = 1;
	}
	
	int ans = n + 1;
	for (int i = 1; i <= m; ++ i) {
		pii mx = mk(0, 0);
		for (int j = 1; j <= m; ++ j) {
			mx = max(mx, mk(cnt[j], j));
		}
		ans = min(ans, mx.fi);
		int x = mx.se;
		vis[x] = 1;
		if (i == m) continue ;
		for (int j = 1; j <= n; ++ j) {
			-- cnt[a[j][now[j]]];
			while (vis[a[j][now[j]]]) ++ now[j];
			++ cnt[a[j][now[j]]];
		}
	}
	printf("%d\n", ans);
	return 0;
}