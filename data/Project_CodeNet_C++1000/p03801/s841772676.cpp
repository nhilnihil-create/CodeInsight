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
using P = std::pair<ll, ll>;

ll N;
ll a[100010];
std::vector<P> vs;
ll cnt[100010];

int main()
{
  std::cin >> N;

  rep( i, N )
  {
    std::cin >> a[i];
    vs.emplace_back( P( a[i], i ) );
  }

  vs.emplace_back( P( 0, N+1 ) );

  std::sort( vs.rbegin(), vs.rend() );

  ll ans = 0, mi = 1ll<<60;

  rep( i, vs.size() )
  {
    ll x1 = vs[i].first, x2 = vs[i+1].first;

    chmin( mi, vs[i].second );

    cnt[mi] += (i+1)*(x1-x2);
  }

  rep( i, N )
    std::cout << cnt[i] << std::endl;

  return 0;
}