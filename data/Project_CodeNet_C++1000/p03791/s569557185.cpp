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
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug "<< i << std::endl

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<ll> x(n);
  rep(i,0,n)std::cin>>x[i];

  ll ans=1;

  std::stack<ll> bot;

  rep(i,0,n){
    bot.push(i);
    ll k=bot.size();
    if(x[i]<2*k-1){
      ans=(ans*k)%MOD;
      bot.pop();
    }
  }

  ll k=bot.size();

  rep(i,1,k+1)ans=(ans*i)%MOD;

  std::cout<<ans;

  return 0;
}
