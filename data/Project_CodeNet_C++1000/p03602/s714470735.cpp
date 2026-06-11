#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

using ll = long long;

int N;
ll A[301][301];
bool fl[301][301];

int main()
{
  scanf( "%d", &N );
  rep( i, N ) rep( j, N )
    scanf( "%lld", &A[i][j] );

  ll dec = 0;
  rep( i, N ) rep( j, i ) rep( k, j )
  {
    if( A[i][j]+A[j][k] < A[i][k] || A[k][i]+A[i][j] < A[k][j] || A[i][k]+A[k][j] < A[i][j] )
    {
      puts("-1");

      return 0;
    }

    if( A[k][j]+A[j][i] == A[k][i] )
      fl[k][i] = fl[i][k] = true;
    if( A[k][i]+A[i][j] == A[k][j] )
      fl[k][j] = fl[j][k] = true;
    if( A[i][k]+A[k][j] == A[i][j] )
      fl[i][j] = fl[j][i] = true;
  }

  ll ans = -dec;
  rep( i, N ) rep( j, i ) if( !fl[i][j] )
    ans += A[i][j];

  printf( "%lld\n", ans );

  return 0;
}