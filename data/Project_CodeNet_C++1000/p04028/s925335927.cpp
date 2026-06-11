#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i )
const int mod = 1e9 + 7, Maxn = 5002;
int f[ Maxn ][ Maxn ];
int main( )
{
	int n, len;
	std::string str;
	std::cin >> n >> str;
	len = str.size( );
	f[ 0 ][ 0 ] = 1;
	For( i, 0, n ) For( j, 0, i )
	{
		if( j == 0 )
			f[ i + 1 ][ j ] = ( f[ i + 1 ][ j ] + f[ i ][ j ] ) % mod;
		else
			f[ i + 1 ][ j - 1 ] = ( f[ i ][ j ] * 2 % mod + f[ i + 1 ][ j - 1 ] ) % mod;
		f[ i + 1 ][ j + 1 ] = ( f[ i + 1 ][ j + 1 ] + f[ i ][ j ] ) % mod; 
	}
	std::cout << f[ n ][ len ];
	return 0; 
} 