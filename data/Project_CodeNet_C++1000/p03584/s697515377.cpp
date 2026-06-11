#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000;

using ll = long long;

ll N, K;
ll A[MAX_N], B[MAX_N];
ll ans;

void f( ll p )
{
  ll sum = 0;

  rep( i, N )
  {
    if( (p|A[i]) == p )
      sum += B[i];
  }

  ans = std::max( ans, sum );

  return;
}

int main()
{
  scanf( "%lld%lld", &N, &K );
  rep( i, N )
    scanf( "%lld%lld", A+i, B+i );

  f( K );

  rep( i, 32 ) if( K >> i & 1 )
    f( (K & (~(1<<i))) | ((1<<i)-1) );

  printf( "%lld\n", ans );

  return 0;
}