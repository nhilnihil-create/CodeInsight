#include <cstdio>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000;

int N;
int p[MAX_N];
bool fl[MAX_N];

int main()
{
  scanf( "%d", &N );
  rep( i, N )
    scanf( "%d", p+i ), fl[i] = i+1 == p[i];

  int p = 0, ans = 0;
  while( p < N )
  {
    if( fl[p] )
    {
      p += 2;
      ++ans;
    }
    else
      ++p;
  }

  printf( "%d\n", ans );

  return 0;
}