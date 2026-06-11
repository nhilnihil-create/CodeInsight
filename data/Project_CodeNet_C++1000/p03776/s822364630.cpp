#include <cstdio>
#include <cmath>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N, A, B;
ll v[60];
ll dp[60][60], dp2[60][60];

int main()
{
  scanf( "%lld%lld%lld", &N, &A, &B );

  rep( i, N )
    scanf( "%lld", v+i );

  dp2[0][0] = 1;

  rep( i, N ) rep( j, i+1 )
  {
    if( chmax( dp[i+1][j+1], dp[i][j]+v[i] ) )
      dp2[i+1][j+1] = dp2[i][j];
    else if( dp[i+1][j+1] == dp[i][j]+v[i] )
      dp2[i+1][j+1] += dp2[i][j];

    if( chmax( dp[i+1][j], dp[i][j] ) )
      dp2[i+1][j] = dp2[i][j];
    else if( dp[i+1][j] == dp[i][j] )
      dp2[i+1][j] += dp2[i][j];
  }

  double ma = 0;
  ll maJ = -1;

  rep( j, N+1 ) if( j >= A && j <= B && chmax( ma, (double)dp[N][j]/j ) )
    maJ = j;

  ll ans = 0;
  rep( j, N+1 ) if( j >= A && j <= B && dp[N][j]*maJ == dp[N][maJ]*j )
    ans += dp2[N][j];

  printf( "%.10f\n", ma );
  printf( "%lld\n", ans );

  return 0;
}