#include <cstdio>
#include <algorithm>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000;

int N, T;
int A[MAX_N];
int ma[MAX_N];
int maI, cnt;

int main()
{
  scanf( "%d%d", &N, &T );
  rep( i, N )
    scanf( "%d", A+i );

  for( int i = N-1; i >= 1; --i )
    ma[i-1] = std::max( A[i], ma[i] );

  rep( i, N )
  {
    if( maI < ma[i]-A[i] )
    {
      maI = ma[i]-A[i];
      cnt = 1;
    }
    else if( maI == ma[i]-A[i] )
      ++cnt;
  }

  printf( "%d\n", cnt );

  return 0;
}