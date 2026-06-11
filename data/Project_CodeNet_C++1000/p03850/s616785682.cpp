#include <cstdio>
#include <iostream>
using namespace std;
#define INF 1e15

const int MAXN = 100000;
int n , x;
long long dp[ 3 ][ MAXN + 5 ];

void Read( int &x ) {
	x = 0; int f = 1;
	char s = getchar( );
	for( ; s < '0' || s > '9' ; s = getchar( ) ) f = s == '-' ? -f : f;
	for( ; s >= '0' && s <= '9' ; s = getchar( ) ) x = x * 10 + s - '0';
	x *= f;
}

int main( ) {
	scanf("%d",&n);
	dp[ 0 ][ 0 ] = 0 , dp[ 1 ][ 0 ] = dp[ 2 ][ 0 ] = -INF;
	for( int i = 1 ; i <= n ; i ++ ) {
		Read( x );
		
		dp[ 0 ][ i ] = max( dp[ 0 ][ i - 1 ] , dp[ 1 ][ i - 1 ] );
		dp[ 1 ][ i ] = max( dp[ 1 ][ i - 1 ] , dp[ 2 ][ i - 1 ] );
		dp[ 2 ][ i ] = dp[ 2 ][ i - 1 ];
		dp[ 0 ][ i ] += x , dp[ 1 ][ i ] -= x , dp[ 2 ][ i ] += x;
		
		if( x < 0 ) {
			dp[ 2 ][ i ] = max( dp[ 2 ][ i ] , dp[ 1 ][ i ] );
			dp[ 1 ][ i ] = max( dp[ 1 ][ i ] , dp[ 0 ][ i ] );
		}
	}
	printf("%lld", max( dp[ 0 ][ n ] , max( dp[ 1 ][ n ] , dp[ 2 ][ n ] ) ) );
	return 0;
}