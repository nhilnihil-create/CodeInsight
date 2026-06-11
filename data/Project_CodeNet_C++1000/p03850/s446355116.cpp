#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::pair;
using std::vector;
const int Maxn = 100005, mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
void cmax( long long &x, long long y )
{
// cout << "x" << x;
 if( y > x )
  x = y;
 return; 
}
int n;
long long f[ Maxn ][ 3 ];
inline long long read( )
{
 int x = 0;
 char ch = getchar( );
 bool f = 0;
 while( !isdigit( ch ) )
  f |= ch == '-',
  ch = getchar( );
 while( isdigit( ch ) )
 {
  x = x * 10 + ch - '0';
  ch = getchar( );
 }
 return f ? -x : x;
}
int main( )
{
 n = read( );
 f[ 0 ][ 0 ] = 0;
 f[ 0 ][ 1 ] = f[ 0 ][ 2 ] = -inf;
 for( int i = 1, x; i <= n; ++i )
 {
  x = read( );
  f[ i ][ 0 ] = std::max( f[ i - 1 ][ 0 ], f[ i - 1 ][ 1 ] );
  f[ i ][ 1 ] = std::max( f[ i - 1 ][ 1 ], f[ i - 1 ][ 2 ] );
  f[ i ][ 2 ] = f[ i - 1 ][ 2 ];
  f[ i ][ 2 ] += x;
  f[ i ][ 1 ] -= x;
  f[ i ][ 0 ] += x;
  if( x < 0 )
   cmax( f[ i ][ 2 ], f[ i ][ 1 ] ),
   cmax( f[ i ][ 1 ], f[ i ][ 0 ] );
//  cout << f[ i ][ 0 ] << " " << f[ i ][ 1 ] << " " << f[ i ][ 2 ] << '\n';
 }
 printf( "%lld", std::max( f[ n ][ 0 ], std::max( f[ n ][ 1 ], f[ n ][ 2 ] ) ) );
 return 0;
}