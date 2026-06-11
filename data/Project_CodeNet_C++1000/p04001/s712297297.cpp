#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i )
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
long long dp[ 20 ], sum[ 20 ], a[ 20 ];
string s;
int main( )
{
	std::ios::sync_with_stdio( false );
	cin >> s;
	dp[ 0 ] = 1;
	For( i, 1, ( int ) s.size( ) )
	{
		dp[ i ] = dp[ i - 1 ] * 2;
		sum[ i ] = sum[ i - 1 ] * 10 + dp[ i - 1 ] * ( s[ i - 1 ] - '0' );
		if( i != s.size( ) )
			a[ i ] = a[ i - 1 ] * 2 + sum[ i ];
		else
			a[ i ] = a[ i - 1 ] + sum[ i ];
	}
	cout << a[ s.size( ) ];
	return 0;
}