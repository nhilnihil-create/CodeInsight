#include <assert.h>
#include <limits.h>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,m;
  std::cin>>n>>m;

  std::vector<ll> x(n),y(m);

  rep(i,0,n)std::cin>>x[i];
  rep(i,0,m)std::cin>>y[i];

  ll xlen=0,ylen=0;

  rep(i,1,n)xlen=(xlen+((i*(n-i))%MOD)*((x[i]-x[i-1])%MOD))%MOD;

  rep(i, 1, m) ylen =(ylen + ((i * (m - i)) % MOD) * ((y[i] - y[i - 1]) % MOD)) % MOD;

  std::cout<<(xlen*ylen)%MOD;

  return 0;
}