#include <cstdio>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;
using P = std::pair<ll, bool>;

ll W, H;
std::vector<P> pqs;

int main()
{
  scanf( "%lld%lld", &W, &H );
  rep( i, W )
  {
    ll p;
    scanf( "%lld", &p );
    pqs.push_back( P( p, false ) );
  }
  rep( i, H )
  {
    ll q;
    scanf( "%lld", &q );
    pqs.push_back( P( q, true ) );
  }

  std::sort( all(pqs) );

  ll a = W+1, b = H+1;
  ll ans = 0;

  for( auto &v : pqs )
  {
    if( v.second )
    {
      ans += a*v.first;
      --b;
    }
    else
    {
      ans += b*v.first;
      --a;
    }
  }

  printf( "%lld\n", ans );

  return 0;
}