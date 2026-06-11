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
ll a[100010];
ll mi = 1ll<<60, ma = 0;

int main()
{
  std::cin >> N;

  rep( i, N )
  {
    std::cin >> a[i];
    chmin( mi, a[i] );
    chmax( ma, a[i] );
  }

  ll cnt = 0;

  rep( i, N )
    cnt += a[i] == ma;

  ll A = cnt/2 + N-cnt;

  if( ma == mi && (mi == N-1 || mi == 1) )
  {
    std::cout << "Yes" << std::endl;

    return 0;
  }

  if( ma-mi > 1 || A != ma || cnt <= 1 )
  {
    std::cout << "No" << std::endl;

    return 0;
  }
  else
    std::cout << "Yes" << std::endl;

  return 0;
}