#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define MAXN 500
#define INF 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, i, j, k, ma, mb, ans = INF;
	cin >> n >> ma >> mb;
	vector<int> a(n), b(n), c(n);
	for (i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

	vector<vector<int>> dp(MAXN, vector<int>(MAXN, INF));
	dp[0][0] = 0;
	for (i = 0; i < n; i++) {
		for (j = MAXN - 1; j >= 0; j--) {
			for (k = MAXN - 1; k >= 0; k--) {
				if ((j + a[i] < MAXN) && (k + b[i] < MAXN))
					dp[j + a[i]][k + b[i]] = min(dp[j + a[i]][k + b[i]], dp[j][k] + c[i]);
			}
		}
	}

	for (i = 1; i < MAXN; i++) {
		for (j = 1; j < MAXN; j++) {
			if (i * mb == j * ma) ans = min(ans, dp[i][j]);
		}
	}

	if (ans == INF) cout << -1 << "\n";
	else cout << ans << "\n";


	return 0;
}

