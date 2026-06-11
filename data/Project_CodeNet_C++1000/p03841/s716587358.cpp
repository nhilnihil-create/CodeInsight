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
#include <unordered_map>
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

//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;

  std::vector<P> x(n);

  std::vector<ll> ans(n*n,-1);

  rep(i,0,n){
    ll temp;
    std::cin>>temp;
    ans[temp-1]=i;
    x[i]={temp-1,i};
  }

  std::sort(all(x));

  ll now=0;

  rep(i,0,n){
    ll value=x[i].second;

    ll count=0;
    while(count<value){
      if(ans[now]==-1){
        count++;
        ans[now]=value;
      }
      now++;
    }
  }

  now=n*n-1;

  for(ll i=n-1;i>=0;i--){
    ll value=x[i].second;

    ll count=0;
    while(count<n-1-value){
      if(ans[now]==-1){
        count++;
        ans[now]=value;
      }
      now--;
    }
  }

  rep(i,0,n){
    ll itr=x[i].first,value=x[i].second;

    ll count=0;
    rep(j,0,itr)if(ans[j]==value)count++;

    if(count!=value){
      std::cout<<"No";
      return 0;
    }
  }

  std::cout<<"Yes\n";

  rep(i,0,n*n)std::cout<<ans[i]+1<<" ";

  return 0;
}
