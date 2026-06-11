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

  ll n,m,ans=m;
  std::cin>>n>>m;

  std::vector<std::vector<ll>> need(n,std::vector<ll>(m));
  rep(i,0,n){
    rep(j,0,m){
      std::cin>>need[i][j];
      need[i][j]--;
    }
  }

  while(1){
    std::vector<ll> count(m,0);
    rep(i,0,n){
      count[need[i][0]]++;
    }
    ll max=0;
    rep(i,0,m)max=std::max(max,count[i]);
    ans=std::min(ans,max);
    rep(i,0,m){
      if(count[i]==max){
        rep(j,0,n){
          auto itr=need[j].begin();
          while(*itr!=i)itr++;
          need[j].erase(itr);
        }
      }
    }

    if(need[0].empty())break;
  }

  std::cout<<ans;

  return 0;
}
