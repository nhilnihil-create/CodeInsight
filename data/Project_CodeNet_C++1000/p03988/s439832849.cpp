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
ll cnt[110];
ll mi = 1ll<<60, ma = 0;
bool fl = true;

int main()
{
  std::cin >> N;

  rep( i, N )
  {
    ll a;
    std::cin >> a;

    ++cnt[a];
    chmax( ma, a );
    chmin( mi, a );
  }

  if( ma % 2 == 0 )
  {
    if( mi != ma/2 )
      fl = false;

    if( cnt[mi] != 1 )
      fl = false;

    repi( i, mi+1, ma+1 )
    {
      if( cnt[i] < 2 )
      {
        fl = false;
        break;
      }
    }
  }
  else
  {
    if( mi != (ma+1)/2 )
      fl = false;

    if( cnt[mi] != 2 )
      fl = false;
    
    repi( i, mi+1, ma+1 )
    {
      if( cnt[i] < 2 )
      {
        fl = false;
        break;
      }
    }
  }

  puts( fl ? "Possible" : "Impossible" );

  return 0;
}