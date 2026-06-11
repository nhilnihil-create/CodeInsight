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

signed main() {
	EmiliaMyWife

	int n, m;
	cin >> n >> m;
	vector<string> arr(n), brr(m);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int j = 0; j < m; j++)
		cin >> brr[j];
	bool ans = 0;
	for(int i = 0; i <= n-m; i++) {
		for(int j = 0; j <= n-m; j++) {
			bool check = true;
			for(int k = 0; k < m; k++)
				check &= (arr[i+k].substr(j, m)==brr[k]);
			ans |= check;
		}
	}
	cout << (ans?"Yes":"No");

	return 0;
}
