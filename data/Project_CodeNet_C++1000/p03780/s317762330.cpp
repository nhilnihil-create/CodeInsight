#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define eps LDBL_EPSILON
#define moder 1000000007
#define double long double
#define INF intONG_MAX/10000
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, k, a[5010];
int dp[2][5010][5010];
signed main() {
	cin >> n >> k;
	rep(i, n)cin >> a[i];
	if (n == 1) {
		if (a[0] >= k)cout << 0 << endl;
		else cout << 1 << endl;
		return 0;
	}
	rep(i, n) {
		if (!i) {
			dp[0][i][0] = 1;
			if (a[i] < k)dp[0][i][a[i]] = 1;
			continue;
		}
		rep(j, k) {
			if (j - a[i] >= 0)dp[0][i][j] |= (bool)dp[0][i - 1][j - a[i]];
			dp[0][i][j] |= (bool)dp[0][i - 1][j];
		}
	}
	rep(i, n) {
		rep(j, k) {
			if (j)dp[0][i][j] += dp[0][i][j - 1];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			dp[1][i][0] = 1;
			if (a[i] < k)dp[1][i][a[i]] = 1;
			continue;
		}
		rep(j, k) {
			if (j - a[i] >= 0)dp[1][i][j] |= (bool)dp[1][i + 1][j - a[i]];
			dp[1][i][j] |= (bool)dp[1][i + 1][j];
		}
	}
	rep(i, n) {
		rep(j, k) {
			if (j)dp[1][i][j] += dp[1][i][j - 1];
		}
	}
	int ans = 0;
	if (k - a[0] - 1 >= 0 && dp[1][1][k - 1] == dp[1][1][k - a[0] - 1] && a[0] < k)ans++;
	else if (k - a[0] - 1 < 0 && dp[1][1][k - 1] == 0 && a[0] < k)ans++;
	for (int i = 1; i < n - 1; i++) {
		bool f = false;
		if (k - a[i] - 1 >= 0 && dp[1][i + 1][k - a[i] - 1] != dp[1][i + 1][k - 1])f = true;
		if (k - a[i] - 1 < 0 && 0 != dp[1][i + 1][k - 1])f = true;
		for (int j = 1; j < k; j++) {
			if (k - j - a[i] - 1 >= 0 && dp[0][i - 1][j - 1] != dp[0][i - 1][j] && dp[1][i + 1][k - j - a[i] - 1] != dp[1][i + 1][k - j - 1])f = true;
			if (k - j - a[i] - 1 < 0 && dp[0][i - 1][j - 1] != dp[0][i - 1][j] && 0 != dp[1][i + 1][k - j - 1])f = true;
		}
		if (!f && a[i] < k)ans++;
	}
	if (k - a[n - 1] - 1 >= 0 && dp[0][n - 2][k - 1] == dp[0][n - 2][k - a[n - 1] - 1] && a[n - 1] < k)ans++;
	else if (k - a[n - 1] - 1 < 0 && dp[0][n - 2][k - 1] == 0 && a[n - 1] < k)ans++;
	cout << ans << endl;
	return 0;
}