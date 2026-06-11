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
const std::string S = "IOTJLSZ";

std::map<char, ll> a;

int main()
{
  rep( i, S.size() )
  {
    ll b;
    std::cin >> b;

    a[S[i]] = b;
  }

  // T, S, Z 除外

  ll ans = a['O'], add = 0;

  rep( b, 2 )
  {
    ll aI = a['I']-b;
    ll aJ = a['J']-b;
    ll aL = a['L']-b;

    if( aI < 0 || aJ < 0 || aL < 0 )
      continue;
    
    chmax( add, b*3+aI/2*2+aJ/2*2+aL/2*2 );
  }

  ans += add;

  std::cout << ans << std::endl;

  return 0;
}