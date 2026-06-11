#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll x, y;
ll ans = 1ll<<60;

int main()
{
  std::cin >> x >> y;

  rep( s1, 2 ) rep( s2, 2 )
  {
    if( (s2?-1:1)*x <= (s1?-1:1)*y )
      chmin( ans, (s1?-1:1)*y-(s2?-1:1)*x+s1+s2 );
  }

  std::cout << ans << std::endl;

  return 0;
}