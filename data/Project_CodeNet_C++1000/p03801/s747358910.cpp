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
#define debug(i) std::cerr <<"debug "<< i << std::endl;

//const ll MOD = 998244353;
const ll MOD = 1e9+7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<P> a(n);
  std::vector<ll> count(n,0);

  rep(i,0,n){
    ll temp;
    std::cin>>temp;
    a[i]={temp,i};
  }

  a.push_back({0,-1});

  std::sort(all(a),std::greater<P>());

  ll min=MOD;

  rep(i,0,n){
    min=std::min(min,a[i].second);
    count[min]+=(i+1)*(a[i].first-a[i+1].first);
  }

  rep(i,0,n)std::cout<<count[i]<<"\n";

  return 0;
}
