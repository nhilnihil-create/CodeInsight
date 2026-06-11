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

ll n;
ll a[100010];
ll S[100010];
ll ans = INF;

int main()
{
  std::cin >> n;

  rep( i, n )
    std::cin >> a[i];

  rep( i, n )
    S[i+1] = S[i]+a[i];  

  rep( fl, 2 ) {
    bool f = fl;
    ll sum = 0, acc = 0;

    rep( i, n ) {
      ll now = S[i]+acc+a[i];

      if( f ) {
        if( now <= 0 ) {
          acc += -now+1;
          sum += -now+1;
        }
      } else {
        if( now >= 0 ) {
          acc -= now+1;
          sum += now+1;
        }
      }

      f ^= true;
    }

    chmin( ans, sum );
  }

  std::cout << ans << std::endl;

  return 0;
}