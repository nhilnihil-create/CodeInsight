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
#include <unordered_map>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}

template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll conv[51][51];

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,a,b;
  std::cin>>n>>a>>b;

  rep(i,1,51){
    conv[i][1]=i;
    rep(j,2,i+1){
      conv[i][j]=conv[i][j-1]*(i+1-j)/j;
    }
  }

  std::vector<ll> v(n);
  rep(i,0,n)std::cin>>v[i];
  std::sort(all(v),std::greater<ll>());

  double sum=0;

  rep(i,0,a)sum+=v[i];
  sum/=a;

  std::cout<<std::setprecision(10)<<std::fixed<<sum<<"\n";

  if(v[0]==v[a-1]){
    ll now=a-1;
    while(now<n&&v[now]==v[0])now++;

    ll ans=0;
    rep(i,a,std::min(b+1,now+1))ans+=conv[now][i];
    std::cout<<ans;
  }else{
    ll start=0;
    while(v[start]!=v[a-1])start++;
    ll last=a-1;
    while(v[last]==v[a-1])last++;

    std::cout<<conv[last-start][a-start];
  }

  return 0;
}




