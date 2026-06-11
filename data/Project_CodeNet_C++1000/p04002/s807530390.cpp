#include <cstdio>
#include <map>
#include <utility>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

using ll = long long;
using P = std::pair<int, int>;

int H, W, N;
std::map<P, ll> m;
ll cnt[10];

int main()
{
  scanf( "%d%d%d", &H, &W, &N );
  rep( i, N )
  {
    int a, b;
    scanf( "%d%d", &a, &b );

    for( int j = -1; j <= 1; ++j ) for( int k = -1; k <= 1; ++k ) if( a+j >= 2 && a+j <= H-1 && b+k >= 2 && b+k <= W-1 )
      ++m[P(a+j,b+k)];
  }

  for( auto it = m.begin(); it != m.end(); ++it )
    ++cnt[it->second];
    
  cnt[0] = (ll)(H-2)*(W-2);
  repi( i, 1, 10 )
    cnt[0] -= cnt[i];

  rep( i, 10 )
    printf( "%lld\n", cnt[i] );

  return 0;
}