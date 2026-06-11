#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill( x, y ) memset( x, y, sizeof x )
#define copy( x, y ) memcpy( x, y, sizeof x )
using namespace std;
 
typedef long long LL;
typedef pair < int, int > pa;
 
const int N = 100010;
 
int n, y[N], x[N], w[N], L, T;
LL cur;
 
int main()
{
#ifdef wxh010910
	freopen( "data.in", "r", stdin );
#endif
	scanf( "%d%d%d", &n, &L, &T );
	for( int i = 0 ; i < n ; i++ )
	{
		scanf( "%d%d", &x[ i ], &w[ i ] );
		if( w[ i ] == 1 )
		{
			y[ i ] = ( x[ i ] + T ) % L;
			cur += ( x[ i ] + T ) / L;
		}
		else
		{
			y[ i ] = ( x[ i ] - T ) % L;
			cur += ( x[ i ] - T ) / L;
			if( y[ i ] < 0 ) y[ i ] += L, cur--;
		}
	}
	cur = ( cur % n + n ) % n;
	sort( y, y + n );
	for( int i = cur ; i < n ; i++ ) printf( "%d\n", y[ i ] );
	for( int i = 0 ; i < cur ; i++ ) printf( "%d\n", y[ i ] );
}