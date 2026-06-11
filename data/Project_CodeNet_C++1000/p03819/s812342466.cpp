#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i ) 
using std::cin;
using std::cout;
using std::pair;
const int N = 3e5 + 1, M = 1e5 + 1;
int n, m, SC1[ M ], SC2[ M ];
pair < int, int > p[ N ];
bool cmp( pair < int, int > p1, pair < int, int > p2 ) { return p1.second - p1.first < p2.second - p2.first; }
void Add( int x )
{
 while( x <= n )
  ++SC2[ x ],
  x += x & -x;
 return;
}
void Sub( int x )
{
 while( x <= n )
  --SC2[ x ],
  x += x & -x;
 return;
}
int Sum( int x )
{
 int res = 0;
 while( x )
  res += SC2[ x ],
  x -= x & -x;
 return res;
}
int main( )
{
 std::ios::sync_with_stdio( false );
 cin >> m >> n;
 For( i, 1, m )
  cin >> p[ i ].first >> p[ i ].second;
 std::sort( p + 1, p + 1 + m, cmp );
 For( i, 1, m )
  SC1[ p[ i ].second - p[ i ].first + 1 ]++;
 for( int i = n - 1; i; --i )
  SC1[ i ] += SC1[ i + 1 ];
 int cur = 1, ans = 0;
 For( d, 1, n )
 {
  ans = SC1[ d ];
  for( int i = d; i <= n; i += d )
   ans += Sum( i );
  cout << ans << '\n';
  while( cur <= m && p[ cur ].second - p[ cur ].first + 1 == d )
  {
   Add( p[ cur ].first );
   Sub( p[ cur ].second + 1 );
   cur++;
  }
 }
 return 0;
}