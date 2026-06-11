#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define clr(a,v) memset((a),(v),sizeof(a))

constexpr int MAX_N = 200000;

using P = std::pair<int, int>;

int N, K, L;
std::vector<int> G[2][MAX_N];
int id[2][MAX_N];
bool used[MAX_N];
int cnt = 0;
std::map<P, int> m;

void dfs( int v, int idx )
{
  if( used[v] )
    return;

  used[v] = true;

  id[idx][v] = cnt;
 
  rep( i, G[idx][v].size() ) if( !used[G[idx][v][i]] )
    dfs( G[idx][v][i], idx );

  return;
}

int main()
{
  scanf( "%d%d%d", &N, &K, &L );
  rep( i, K )
  {
    int p, q;
    scanf( "%d%d", &p, &q );
    --p; --q;
    G[0][p].push_back( q );
    G[0][q].push_back( p );
  }
  rep( i, L )
  {
    int r, s;
    scanf( "%d%d", &r, &s );
    --r; --s;
    G[1][r].push_back( s );
    G[1][s].push_back( r );
  }

  rep( i, N )
    dfs( i, 0 ), ++cnt;

  clr( used, false );
  cnt = 0;
  rep( i, N )
    dfs( i, 1 ), ++cnt;

  rep( i, N )
    ++m[P(id[0][i], id[1][i])];

  rep( i, N )
    printf( "%d%c", m[P(id[0][i], id[1][i])], i==N-1?'\n':' ' );

  return 0;
}