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
#define debug(i) std::cout <<"debug "<< i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;

ll max[20][100010];
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,l,q;

  std::cin>>n;
  std::vector<ll> x(n);
  rep(i,0,n)std::cin>>x[i];

  std::cin>>l>>q;

  rep(i,0,n)max[0][i]=(ll)(std::upper_bound(all(x),x[i]+l)-x.begin())-1;

  rep(k,1,20){
    rep(i,0,n){
      max[k][i]=max[k-1][max[k-1][i]];
    }
  }



  rep(_,0,q){
    ll a,b,ans=MOD;
    std::cin>>a>>b;
    a--;b--;
    if(a>b)std::swap(a,b);
    ll now=a,temp=0;
    for(ll i=(1<<19),pow=19;i>0;i/=2,pow--){
      if(max[pow][now]>=b){
        ans=std::min(ans,temp+i);
      }else{
        temp+=i;
        now=max[pow][now];
      }
    }
    std::cout<<ans<<"\n";
  }

  return 0;
}
