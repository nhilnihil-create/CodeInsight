/*
--------------              |   /
      |                     |  /
      |                     | /
      |             *       |/          |    |         ------            *
      |                     |           |    |        /      \
      |             |       |\          |    |       |       |\          |
   \  |             |       | \         |    |       |       | \         |
    \ |             |       |  \        |    |        \     /   \        |
     V              |       |   \        \__/|         -----     \       |
*/
#include <bits/stdc++.h>
using namespace std;

#define EmiliaMyWife ios::sync_with_stdio(0); cin.tie(NULL);
#define mem(i,j) memset(i,j,sizeof (i));
#define F first
#define S second
#define lowbit(x) ((x)&(-(x)))
#define siz(v) (long long)(v).size()
typedef int64_t ll;
typedef uint64_t ull;
const double EPS  = 1e-8;
const int INF     = 0x3F3F3F3F;
const ll LINF     = 4611686018427387903;
const int MOD     = 1e9+7;
/*-----------------------------------------------------------------------------------------------------*/

int dp[401][401];
signed main() {
	EmiliaMyWife

	for(int i = 0; i < 401; i++)
		for(int j = 0; j < 401; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	int n, a, b, ans = INF;
	cin >> n >> a >> b;
	for(int i = 0, x, y, c; i < n; i++) {
		cin >> x >> y>> c;
		for(int j = 400; j >= x; j--) {
			for(int k = 400; k>= y; k--) {
				dp[j][k] = min(dp[j][k], dp[j-x][k-y]+c);
			}
		}
	}
	for(int i = 1; max(i*a, i*b) <= 400; i++)
		ans = min(ans, dp[i*a][i*b]);
	if(ans == INF)
		ans = -1;
	cout << ans;

	return 0;
}
