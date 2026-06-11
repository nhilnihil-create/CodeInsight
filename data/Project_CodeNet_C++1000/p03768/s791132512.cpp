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
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << (x) << endl;

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

ll N, M;
std::vector<ll> G[100010];
ll Q;
ll v[100010], d[100010], c[100010];
bool memo[100010][20];
ll ans[100010];

void func( ll ver, ll dist, ll col ) {
  if( memo[ver][dist] )
    return;

  bool &ret = memo[ver][dist];

  if( !ans[ver] )
    ans[ver] = col;

  if( !dist )
    return;

  for( auto u : G[ver] )
    func( u, dist-1, col );

  ret = true;

  return;
}

int main() {
  std::cin >> N >> M;

  rep( i, M ) {
    ll a, b;
    std::cin >> a >> b;
    --a; --b;

    G[a].emplace_back( b );
    G[b].emplace_back( a );
  }

  std::cin >> Q;

  rep( q, Q ) {
    std::cin >> v[q] >> d[q] >> c[q];
    --v[q];
  }

  repd( q, Q ) {
    func( v[q], d[q], c[q] );
  }

  rep( i, N )
    std::cout << ans[i] << endl;

  return 0;
}