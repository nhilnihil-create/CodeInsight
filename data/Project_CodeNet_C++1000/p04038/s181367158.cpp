#include <cstdio>

const int MAXN = 2000 , MAXM = MAXN * MAXN , Mod = 1e9 + 7;
int n , k , Fac[ MAXM + 5 ] , Inv[ MAXM + 5 ] , dp[ MAXN + 5 ][ MAXN + 5 ];

int Quick_pow( int x , int po ) {
	int Ans = 1;
	for( ; po ; po >>= 1 , x = 1ll * x * x % Mod )
		if( po & 1 ) Ans = 1ll * Ans * x % Mod;
	return Ans;
}
void Init( ) {
	Fac[ 0 ] = 1;
	for( int i = 1 ; i <= MAXM ; i ++ )
		Fac[ i ] = 1ll * Fac[ i - 1 ] * i % Mod;
	Inv[ MAXM ] = Quick_pow( Fac[ MAXM ] , Mod - 2 );
	for( int i = MAXM - 1 ; i >= 0 ; i -- )
		Inv[ i ] = 1ll * Inv[ i + 1 ] * ( i + 1 ) % Mod;
}
int C( int n , int m ) {
	return 1ll * Fac[ n ] * Inv[ m ] % Mod * Inv[ n - m ] % Mod;
}

int main( ) {
	Init( );
	scanf("%d %d",&n,&k);
	if( k == 1 ) return !printf("%d\n", 1 );
	
	for( int i = 1 ; i <= n ; i ++ )
		dp[ i ][ 0 ] = 1;
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= i ; j ++ )
			dp[ i ][ j ] = ( dp[ i - 1 ][ j ] + 1ll * dp[ i ][ j - 1 ] * ( n - j + 1 ) % Mod * C( n * k - i - ( j - 1 ) * ( k - 1 ) - 1 , k - 2 ) % Mod ) % Mod;// , printf("%d%c",dp[i][j],j==i?'\n':' ');
	printf("%d\n", dp[ n ][ n ] );
	return 0;
}