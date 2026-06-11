#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;

int a[MAXN], n;

inline bool solve()
{
	int cnt0 = 0, cnt1 = 0, d = 0;
	for( int i = 1 ; i <= n ; i++ )
		if( a[ i ] & 1 ) cnt1++;
		else cnt0++;
	if( cnt0 & 1 ) return true;
	if( cnt1 ^ 1 ) return false;
	for( int i = 1 ; i <= n ; i++ )
		if( ( a[ i ] & 1 ) && ( a[ i ] != 1 ) )
		{
			a[ i ]--;
			for( int j = 1 ; j <= n ; j++ ) d = __gcd( d, a[ j ] );
			for( int j = 1 ; j <= n ; j++ ) a[ j ] /= d;
			return ( solve() ^ 1 );
		}
	return false;
}

int main()
{
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ ) scanf( "%d", &a[ i ] );
	if( n == 1 ) return printf( "Second\n" ), 0;
	if( solve() ) return printf( "First\n" ), 0;
	return printf( "Second\n" ), 0;
}
