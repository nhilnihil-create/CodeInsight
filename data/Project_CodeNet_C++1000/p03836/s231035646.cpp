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

void print(char x, int t) {
	while(t--)
		cout << x;
}

signed main() {
	EmiliaMyWife

	int x, y, a, b;
	cin >> x >> y >> a >> b;
	print('U', b-y);
	print('R', a-x);
	print('D', b-y);
	print('L', a-x);
	print('D', 1);
	print('R', a-x+1);
	print('U', b-y+1);
	print('L', 1);
	print('U', 1);
	print('L', a-x+1);
	print('D', b-y+1);
	print('R', 1);

	return 0;
}
