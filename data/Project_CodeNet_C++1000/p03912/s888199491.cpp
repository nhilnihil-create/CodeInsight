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

  ll n,m;
  std::cin>>n>>m;

  std::vector<ll> x(n),count(m,0),max(m,0);
  rep(i,0,n)std::cin>>x[i];

  std::sort(all(x));

  ll prv=x[0],temp=0;
  rep(i,0,n){
    if(prv!=x[i]){
      max[prv%m]+=temp/2;
      temp=1;
      prv=x[i];
    }else{
      temp++;
    }
    count[x[i]%m]++;
  }
  max[prv%m]+=temp/2;

  ll ans=count[0]/2+((m%2==0)?count[m/2]/2:0);

  rep(i,1,(m+1)/2){
    ll temp1,temp2,same;
    if(count[i]>count[m-i]){
      temp1=count[m-i];temp2=count[i];
      same=max[i];
    }else{
      temp1=count[i];temp2=count[m-i];
      same=max[m-i];
    }

    ans+=temp1;
    ans+=std::min((temp2-temp1)/2,same);
  }

  std::cout<<ans;

  return 0;
}
