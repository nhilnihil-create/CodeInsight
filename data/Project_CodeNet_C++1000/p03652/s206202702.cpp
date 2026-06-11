#include <bits/stdc++.h>
using namespace std;

const int inf = 1000005;
const int maxn = 302;

int n, m, ans, mx_cnt, mx_sport;
int a[maxn][maxn], pos[maxn], cnt[maxn];
bool rem[maxn];

signed main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		pos[i] = 1;
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	}
	ans = inf;
	for (int w = 1; w <= m; ++w) {
		memset(cnt, 0, sizeof(cnt));
		mx_cnt = mx_sport = 0;
		for (int i = 1; i <= n; ++i) {
			++cnt[a[i][pos[i]]];
			if (mx_cnt < cnt[a[i][pos[i]]]) 
				mx_cnt = cnt[a[i][pos[i]]], mx_sport = a[i][pos[i]];
		}
		ans = min(ans, mx_cnt);
		if (w != m) {
			rem[mx_sport] = 1;
			for (int i = 1; i <= n; ++i) {
				while (rem[a[i][pos[i]]])
					++pos[i];
			}
		}
	}
	printf("%d\n", ans);
}
