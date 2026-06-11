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

  std::string s,t;
  std::cin>>s>>t;
  ll n=s.size(),m=t.size();

  std::vector<ll> scnt(n+1,0),tcnt(m+1,0);

  rep(i,0,n)scnt[i+1]=scnt[i]+((s[i]=='A')?1:0);
  rep(i,0,m)tcnt[i+1]=tcnt[i]+((t[i]=='A')?1:0);

  ll q;
  std::cin>>q;

  rep(i,0,q){
    ll a,b,c,d;
    std::cin>>a>>b>>c>>d;
    ll temp1=2*(scnt[b]-scnt[a-1])-b+a-1;
    ll temp2=2*(tcnt[d]-tcnt[c-1])-d+c-1;
    if((temp1-temp2+3*100000)%3==0)std::cout<<"YES\n";
    else std::cout<<"NO\n";
  }

  return 0;
}
