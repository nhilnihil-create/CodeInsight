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
#define debug(i) std::cout << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,a,b,max=0;
  std::cin>>n>>a>>b;
  std::vector<ll> h(n);
  rep(i,0,n){
    std::cin>>h[i];
    max=std::max(max,h[i]);
  }

  ll left=0,right=max/b+1;

  while(right-left>1){
    ll mid=left+(right-left)/2;

    ll count=0;
    rep(i,0,n){
      if(h[i]-mid*b>0){
        count+=(h[i]-mid*b-1)/(a-b)+1;
      }
    }

    if(count<=mid)right=mid;
    else left=mid;
  }

  std::cout<<right;
  return 0;
}