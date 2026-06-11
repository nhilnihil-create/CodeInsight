#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long LL;

const int MAXN = 100010;

int n, m, size, flag, cnt1, cnt2, cnt3, col[MAXN];
LL ans;
vector < int > G[MAXN];

inline void dfs(int x, int c)
{
	size++;
	col[ x ] = c;
	for( auto y : G[ x ] )
		if( col[ y ] == -1 ) dfs( y, c ^ 1 );
		else if( col[ y ] == c ) flag = 1;
}

int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d%d", &n, &m );
	memset( col, -1, sizeof col );
	for( int i = 1, x, y ; i <= m ; i++ ) scanf( "%d%d", &x, &y ), G[ x ].pb( y ), G[ y ].pb( x );
	for( int i = 1 ; i <= n ; i++ ) if( col[ i ] == -1 )
	{
		size = flag = 0;
		dfs( i, 0 );
		if( size == 1 ) cnt1++;
		else if( flag ) cnt2++;
		else cnt3++;
	}
	ans = 2LL * cnt1 * n - 1LL * cnt1 * cnt1;
	ans += 1LL * cnt2 * cnt2 + 2LL * cnt2 * cnt3 + 2LL * cnt3 * cnt3;
	cout << ans << endl;
	return 0;
}
