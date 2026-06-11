#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
std::vector<ll> G[100010];
ll dp[100010];
bool used[100010];

ll dfs( ll v, ll p )
{
  used[v] = true;

  std::vector<ll> vs;

  for( auto u : G[v] ) if( u != p && !used[u] )
    vs.emplace_back( dfs( u, v ) );
  
  std::sort( vs.rbegin(), vs.rend() );

  rep( i, vs.size() )
    chmax( dp[v], vs[i]+i+1 );

  return dp[v];
}

int main()
{
  std::cin >> N;

  rep( i, N-1 )
  {
    ll a;
    std::cin >> a;
    --a;

    G[a].emplace_back( i+1 );
  }

  dfs( 0, -1 );

  std::cout << dp[0] << std::endl;

  return 0;
}