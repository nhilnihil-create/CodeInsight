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

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];

  std::sort(all(a));

  if(a[n-1]-a[0]>1){
    std::cout<<"No";
    return 0;
  }

  if(a[n-1]==a[0]){
    if(a[0]==n-1 || 2*a[0]<=n)std::cout<<"Yes";
    else std::cout<<"No";
  }else{
    ll cnt=0,itr=0;
    while(a[itr]==a[0]){
      cnt++;itr++;
    }
    if(cnt<a[n-1]&&2*(a[n-1]-cnt)<=n-cnt)std::cout<<"Yes";
    else std::cout<<"No";
  }

  return 0;
}
