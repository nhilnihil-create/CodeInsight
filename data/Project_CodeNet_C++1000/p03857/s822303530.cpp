#include <bits/stdc++.h>
const int Maxn = 2e5 + 1;
int f1[ Maxn ], f2[ Maxn ], n, k, l;
std::map < std::pair < int, int >, int > mp;
int p, q;
int find( int *f, int x )
{
 return f[ x ] == x ? x : f[ x ] = find( f, f[ x ] ); 
}
void merge( int *f, int x, int y )
{
 int x1 = find( f, x ), y1 = find( f, y );
 if( x1 == y1 )
  return;
 f[ y1 ] = x1;
 return;
}
int main( )
{
 std::ios::sync_with_stdio( false );
 std::cin >> n >> k >> l;
 for( int i = 1; i <= n; ++i )
  f1[ i ] = f2[ i ] = i;
 for( int i = 1; i <= k; ++i )
 {
  std::cin >> p >> q;
  merge( f1, p, q );
 }
 for( int i = 1; i <= l; ++i )
 {
  std::cin >> p >> q;
  merge( f2, p, q );
 }
 for( int i = 1; i <= n; ++i )
  find( f1, i ),
  find( f2, i );
 for( int i = 1; i <= n; ++i )
  mp[ std::make_pair( f1[ i ], f2[ i ] ) ]++; 
 for( int i = 1; i <= n; ++i )
  std::cout << mp[ std::make_pair( f1[ i ], f2[ i ] ) ] << " ";
 return 0;
}