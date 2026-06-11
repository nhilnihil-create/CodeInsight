#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}

template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll dp[41][410][410];

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  rep(i,0,41)rep(j,0,410)rep(k,0,410)dp[i][j][k]=MOD;

  ll n,ma,mb;
  std::cin>>n>>ma>>mb;

  dp[0][0][0]=0;

  rep(i,0,n){
    ll a,b,c;
    std::cin>>a>>b>>c;
    rep(j,0,410)rep(k,0,410)chmin(dp[i+1][j][k],dp[i][j][k]);
    rep(j,a,410)rep(k,b,410)chmin(dp[i+1][j][k],dp[i][j-a][k-b]+c);
  }

  ll ans=MOD;

  rep(i,1,400/std::max(ma,mb)+1){
    chmin(ans,dp[n][i*ma][i*mb]);
  }

  if(ans==MOD)std::cout<<-1;
  else std::cout<<ans;

  return 0;
}




