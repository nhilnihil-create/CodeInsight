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

int dp[101][101];

signed main() {
	EmiliaMyWife

	memset(dp, 0x3F, sizeof dp);
	int n, m;
	vector<pair<pair<int,int>, int>> edge;
	cin >> n >> m;
	for(int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({{a, b}, c});
		dp[a][b] = dp[b][a] = c;
	}
	for(int i = 1; i <= 100; i++)
		dp[i][i] = 0;
	for(int k = 1; k <= 100; k++)
		for(int i = 1; i <= 100; i++)
			for(int j = 1; j <= 100; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	int ans = 0;
	for(auto &x : edge) {
		if(dp[x.first.first][x.first.second] != x.second)
			ans++;
	}
	cout << ans;

	return 0;
}
