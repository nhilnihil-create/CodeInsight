#include <cstdio>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

using ll = long long;

ll N, L, T;
std::vector<ll> vs;
ll cnt;

int main()
{
  scanf( "%lld%lld%lld", &N, &L, &T );
  rep( i, N )
  {
    ll X, W;
    scanf( "%lld%lld", &X, &W );

    if( W == 1 )
    {
      vs.emplace_back( (X+T)%L );
      cnt -= (T-(L-X)+L)/L;
    }
    else
    {
      vs.emplace_back( ((X-T)%L+L)%L );
      cnt += (T-(X+1)+L)/L;
    }
  }

  cnt = (cnt%N+N)%N;

  std::sort( all(vs) );

  rep( i, N )
    printf( "%lld\n", vs[(i-cnt+N)%N] );
  
  return 0;
}