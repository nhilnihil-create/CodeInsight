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
  return os << "[" << pa.first << ", " << pa.second << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  os << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  os << "}";
  return os;
}

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

//非再帰累乗(mod付き)
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }

  ll x = 1;

  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::string s;
  std::cin>>n>>s;
  ll m=s.size();

  std::vector<std::vector<ll>> dp(n+1,std::vector<ll>(n+1,0));

  dp[0][0]=1;

  rep(i,1,n+1){
    dp[i][0]=(dp[i-1][1]+dp[i-1][0])%MOD;
    dp[i][n]=(2*dp[i-1][n-1])%MOD;
    rep(j,1,n){
      dp[i][j]=(dp[i-1][j-1]*2+dp[i-1][j+1])%MOD;
    }
  }

  std::cout<<(dp[n][m]*pow_mod(5*1e8+4,m,MOD))%MOD;

  return 0;
}