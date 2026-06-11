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
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll N;
ll prv, ans;

int main()
{
  std::cin >> N;

  rep( i, N )
  {
    ll A;
    std::cin >> A;

    if( !prv )
    {
      ans += A-1;
      prv = 1;
    }
    else if( A == prv+1 )
      ++prv;
    else if( A > prv+1 )
      ans += (A-1)/(prv+1);
  }

  std::cout << ans << std::endl;

  return 0;
}