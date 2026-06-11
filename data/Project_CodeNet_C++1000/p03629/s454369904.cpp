#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
#include <tuple>
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

std::string A;
ll nxt[200010][30];
std::map<ll, ll> mp;
ll dp[200010];

int main() {
  std::cin >> A;

  ll N = A.size();

  repd( i, N ) {
    mp[A[i]-'a'] = i;

    rep( c, 26 ) {
      if( mp.count(c) )
        nxt[i][c] = mp[c];
      else
        nxt[i][c] = N;
    }
  }

  rep( i, N+1 )
    dp[i] = INF;

  dp[N] = 1;
  dp[N+1] = 0;

  repd( i, N ) rep( c, 26 ) {
    chmin( dp[i], dp[nxt[i][c]+1]+1 );
  }

  std::string ans;

  for( ll i = 0; i < N; ++i ) {
    rep( c, 26 ) if( dp[i] == dp[nxt[i][c]+1]+1 ) {
      ans += c+'a';
      i = nxt[i][c];
      break;
    }
  }

  std::cout << ans << endl;

  return 0;
}