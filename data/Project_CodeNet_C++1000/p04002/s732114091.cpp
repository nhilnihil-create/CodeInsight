#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i )
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::string;
std::map < pair < int, int >, int > mp, mp1;
int h, w, n;
int dx[ 9 ] = { -1, 0, 1, 1, 1, 0, -1, -1, 0 },
				dy[ 9 ] = { 1, 1, 1, 0, -1, -1, -1, 0, 0 };
long long cnt[ 10 ];
int main( )
{
	std::ios::sync_with_stdio( false );
	cin >> h >> w >> n;
	cnt[ 0 ] = ( long long ) ( h - 2 ) * ( w - 2 );
	vector < pair<int, int > > a;
	int u, v;
	For( i, 1, n )
	{
		cin >> u >> v;
		std::pair < int, int > I;
		mp[ I = std::make_pair( u, v ) ] = 1; 
		For( k, 0, 8 ) if( I.first + dx[ k ] >= 2 && I.second + dy[ k ] >= 2 && I.first + dx[ k ] <= h - 1 && I.second + dy[ k ] <= w - 1 )
			a.push_back( std::make_pair( u + dx[ k ], v + dy[ k ] ) );
	}
	for( auto &i : a )
	{
		if( mp1[ i ] == 1 )
			continue;
		mp1[ i ] = 1;
		int o = 0;
		For( k, 0, 8 ) if( i.first + dx[ k ] >= 1 && i.second + dy[ k ] >= 1 && i.first + dx[ k ] <= h && i.second + dy[ k ] <= w )
			o += mp.count( std::make_pair( i.first + dx[ k ], i.second + dy[ k ] ) );
		cnt[ o ]++;
		cnt[ 0 ]--;
	}
	For( i, 0, 9 )
		cout << cnt[ i ] << '\n';
	return 0;
}