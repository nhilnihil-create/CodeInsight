#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::pair;
#define For( i, j, k ) for( int i = j; i <= k; ++i )
const int N = 1e5 + 1;
int n;
long long ans[ N ];
pair < int, int > p[ N ];
int main( )
{
 std::ios::sync_with_stdio( false );
 cin >> n;
 For( i, 1, n )
  cin >> p[ i ].first,
  p[ i ].second = i;
 std::sort( p + 1, p + 1 + n, std::greater < pair < int, int > > ( ) );
 int top = 1, id = 0x3f3f3f3f;
 for( int i = 1; i <= n; )
 {
  while( top <= n && p[ top ].first >= p[ i ].first )
   ++top;
  id = std::min( id, p[ top - 1 ].second );
  ans[ id ] += 1LL * ( p[ top - 1 ].first - p[ top ].first ) * ( top - 1 );
  i = top;
 }
 For( i, 1, n )
  cout << ans[ i ] << '\n';
 return 0;
}