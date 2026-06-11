#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <type_traits>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;
using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector< int >;
using VVI = vector< vector< int > >;
using VS = vector< string >;
using SS = stringstream;
using PII = pair< int, int >;
using VPII = vector< pair< int, int > >;
template < typename T = int > using VT = vector< T >;
template < typename T = int > using VVT = vector< vector< T > >;
template < typename T = int > using LIM = numeric_limits< T >;

template < typename T > inline istream& operator>>( istream &s, vector< T > &v ){ for ( T &t : v ) { s >> t; } return s; }
template < typename T > inline ostream& operator<<( ostream &s, const vector< T > &v ){ for ( int i = 0; i < int( v.size() ); ++i ){ s << ( " " + !i ) << v[i]; } return s; }
template < typename T > inline T fromString( const string &s ) { T res; istringstream iss( s ); iss >> res; return res; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

#define NUMBERED( name, number ) NUMBERED2( name, number )
#define NUMBERED2( name, number ) name ## _ ## number
#define REP1( n ) REP2( NUMBERED( REP_COUNTER, __LINE__ ), n )
#define REP2( i, n ) REP3( i, 0, n )
#define REP3( i, m, n ) for ( int i = ( int )( m ); i < ( int )( n ); ++i )
#define GET_REP( a, b, c, F, ... ) F
#define REP( ... ) GET_REP( __VA_ARGS__, REP3, REP2, REP1 )( __VA_ARGS__ )
#define FOR( e, c ) for ( auto &&e : c )
#define ALL( c ) begin( c ), end( c )
#define AALL( a ) ( std::remove_all_extents< decltype( a ) >::type * )a, ( std::remove_all_extents< decltype( a ) >::type * )a + sizeof( a ) / sizeof( std::remove_all_extents< decltype( a ) >::type )
#define DRANGE( c, p ) ( c ).begin(), ( c ).begin() + ( p ), ( c ).end()

#define SZ( v ) ( (int)( v ).size() )
#define EXIST( c, e ) ( ( c ).find( e ) != ( c ).end() )

template < typename T > inline bool chmin( T &a, const T &b ){ if ( b < a ) { a = b; return true; } return false; }
template < typename T > inline bool chmax( T &a, const T &b ){ if ( a < b ) { a = b; return true; } return false; }

#define PB push_back
#define EM emplace
#define EB emplace_back
#define BI back_inserter

#define MP make_pair
#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

constexpr int X_MAX = 100'000;

int pairing( VI &A, int K )
{
	sort( ALL( A ) );

	int res = 0;
	VI B;
	REP( i, SZ( A ) )
	{
		if ( K && i + 1 < SZ( A ) && A[i] == A[ i + 1 ])
		{
			++i;
			++res;
			--K;
			continue;
		}

		B.PB( A[i] );
	}
	A = B;
	return res;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );
	cout << setprecision( 12 ) << fixed;

	int N, M;
	scanf( "%d%d!", &N, &M );

	VI X( N );
	for_each( ALL( X ), [=]( int &x ){ scanf( "%d", &x ); } );

	VI counts( X_MAX + 1 );
	for_each( ALL( X ), [&]( const int &x ){ ++counts[x]; } );

	VVI cards( M );
	FOR( x, X )
	{
		cards[ x % M ].PB( x );
	}

	int res = 0;
	REP( i, 1, ( M + 1 ) / 2 )
	{
		auto &a = cards[i], &b = cards[ M - i ];
		const int d = abs( SZ( a ) - SZ( b ) );
		res += pairing( SZ( a ) < SZ( b ) ? b : a, d / 2 );
	}

	res += SZ( cards[0] ) / 2;
	if ( M % 2 == 0 )
	{
		res += SZ( cards[ M / 2 ] ) / 2;
	}

	REP( i, 1, ( M + 1 ) / 2 )
	{
		res += min( SZ( cards[i] ), SZ( cards[ M - i ] ) );
	}

	printf( "%d\n", res );
	fflush( stdout );

	return 0;
}
