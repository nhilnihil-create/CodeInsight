#include <cstdio>
#include <cstring>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define clr(a,v) memset((a),(v),sizeof(a))

constexpr int MAX_N = 100000;

int N;
std::vector<int> G[MAX_N];
int d[2][MAX_N];
bool used[MAX_N];
int cnt[2];

void dfs( int v, int idx )
{
  used[v] = true;

  rep( i, G[v].size() ) if( !used[G[v][i]] )
  {
    d[idx][G[v][i]] = d[idx][v]+1;
    dfs( G[v][i], idx );
  }

  return;
}

int main()
{
  scanf( "%d", &N );
  rep( i, N-1 )
  {
    int a, b;
    scanf( "%d%d", &a, &b );
    --a; --b;
    G[a].push_back( b );
    G[b].push_back( a );
  }

  dfs( 0, 0 );

  clr( used, false );
  dfs( N-1, 1 );

  rep( i, N )
  {
    if( d[0][i] <= d[1][i] )
      ++cnt[0];
    else
      ++cnt[1];
  }

  puts( cnt[0] > cnt[1] ? "Fennec" : "Snuke" );

  return 0;
}