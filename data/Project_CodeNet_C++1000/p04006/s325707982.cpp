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

  ll n,x,ans=LLONG_MAX;
  std::cin>>n>>x;

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];
  
  std::vector<std::vector<ll>> min(n,std::vector<ll>(n));

  rep(i,0,n){
    min[i][0]=a[i];
    rep(j,1,n)min[i][j]=std::min(min[i][j-1],a[(i-j+n)%n]);
  }

  rep(i,0,n){
    ll temp=0;
    rep(j,0,n)temp+=min[j][i];
    ans=std::min(ans,i*x+temp);
  }

  std::cout<<ans;

  return 0;
}
