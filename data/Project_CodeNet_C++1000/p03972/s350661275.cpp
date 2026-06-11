#include <cstdio>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

using T = std::pair<bool, int>;
using P = std::pair<ll, T>;

ll W, H;
ll p[100010], q[100010];
std::vector<P> ps;

int main()
{
  scanf( "%lld%lld", &W, &H );
  rep( i, W )
  {
    scanf( "%lld", p+i );
    ps.push_back( P( p[i], T( false, i ) ) );
  }
  rep( i, H )
  {
    scanf( "%lld", q+i );
    ps.push_back( P( q[i], T( true, i ) ) );
  }

  std::sort( all(ps) );

  ll ans = 0;

  rep( i, ps.size() )
  {
    if( W <= 0 && H <= 0 )
      break;

    if( ps[i].second.first )
    {
      ans += ps[i].first*(W+1);
      --H;
    }
    else
    {
      ans += ps[i].first*(H+1);
      --W;
    }
  }

  printf( "%lld\n", ans );

  return 0;
}