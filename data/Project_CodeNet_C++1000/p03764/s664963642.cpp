#include <bits/stdc++.h>

#define gc( ) std::getchar( )
#define pc( i ) std::putchar( i )
#define space ' '
#ifdef ONLINE_JUDGE
#define enter '\n'
#else
#define enter std::endl
#endif
#define RE cout << "Passing [" << __FUNCTION__ << "] on " << __LINE__ << enter
#define DEBUG(...) for( auto &i: __VA_ARGS__ ) cout << i << " "; cout << enter
using std::make_pair;

template < typename T >
inline T read( )
{
 T x = 0;
 char ch = gc( );
 bool f = 0;
 while( !std::isdigit( ch ) )
 {
  f = ( ch == '-' );
  ch = gc( );
 }
 while( std::isdigit( ch ) )
 {
  x = x * 10 + ( ch - '0' );
  ch = gc( );
 }
 return f ? -x : x;
}

template < typename T >
void print( T x )
{
 if( x < 0 )
 {
  x = -x;
  pc( '-' );
 }
 if( x < 10 )
 {
  pc( x + 48 );
  return;
 }
 print < T > ( x / 10 );
 pc( x % 10 + 48 );
 return ;
}

namespace Solution
{
#define IOS std::ios::sync_with_stdio( false ), std::cin.tie( 0 ), std::cout.tie( 0 )
#define Rep( i, j, k ) for( int i = j; i >= k; --i )
#define rdi( ) read < int > ( )
#define rdl( ) read < long long > ( )
#define pti( i ) print < int > ( i ), putchar( space )
#define ptl( i ) print < long long > ( i ), putchar( space )
#define For( i, j, k ) for( int i = j; i <= k; ++i )
 using std::cin;
 using std::cout;
 using std::endl;
 using std::vector;
 using std::map;
 using std::queue;
 using std::deque;
 using std::set;
 using std::pair;
 const int N = 104001, mod = 1e9 + 7;
 int n, m, x[ N ], y[ N ];
 long long ansx, ansy;
 void Fakemain( )
 {
  n = rdi( );
  m = rdi( );
  For( i, 1, n )
  {
   x[ i ] = ( rdi( ) % mod + mod ) % mod;
   ansx = ( ansx + 1LL * ( 2 * i - n - 1 ) * x[ i ] ) % mod; 
  }
  For( i, 1, m )
  {
   y[ i ] = ( rdi( ) % mod + mod ) % mod;
   ansy = ( ansy + 1LL * ( 2 * i - m - 1 ) * y[ i ] ) % mod; 
  }
  ptl( ansx * ansy % mod );
  return;
 }

} // namespace Solution

int main( int argc, char* argv[] )
{
 Solution::Fakemain( );
 return 0;
}