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

  ll n,t;
  std::cin>>n>>t;
  ll min;
  std::vector<ll> b(n-1);
  std::cin>>min;
  rep(i,1,n){
    ll a;
    std::cin>>a;
    b[i-1]=a-min;
    min=std::min(min,a);
  }
  std::sort(all(b));
  ll max=b[n-2];
  std::cout<<(ll)(b.end()-std::lower_bound(all(b),max));
  return 0;
}