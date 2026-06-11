#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000037;
const int maxn = 41;
const int maxs = 401;

int n, ma, mb, ans = inf;
int dp[maxn][maxs][maxs];
pair < int, pair < int, int > > cab[maxn];

void prepare () {
	for (int i = 0; i < maxn; ++i) {
		for (int j = 0; j < maxs; ++j) {
			for (int w = 0; w < maxs; ++w) {
				if (j || w)
					dp[i][j][w] = inf;
			}
		}
	}
}

signed main () {
	prepare();
	
	scanf("%d %d %d", &n, &ma, &mb);
	for (int i = 1; i <= n; ++i) 
		scanf("%d %d %d", &cab[i].second.first, &cab[i].second.second, &cab[i].first);
	sort(cab + 1, cab + n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < maxs; ++j) {
			for (int w = 1; w < maxs; ++w) {
				dp[i][j][w] = dp[i - 1][j][w];
				if (j >= cab[i].second.first && w >= cab[i].second.second)
					dp[i][j][w] = min(dp[i][j][w], dp[i - 1][j - cab[i].second.first][w - cab[i].second.second] + cab[i].first);
			}
		}
	}
	for (int i = ma; max(i, (i / ma) * mb) < maxs; i += ma) 
		ans = min(ans, dp[n][i][(i / ma) * mb]);
	if (ans == inf)
		ans = -1;
	printf("%d\n", ans);
}
