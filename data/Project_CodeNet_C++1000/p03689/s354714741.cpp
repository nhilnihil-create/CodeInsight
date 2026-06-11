#include <cassert>
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
#include <random>
#include <memory>
#include <utility>
#include <limits>
#include "limits.h"
 
#define rep(i, a, b) for (long long (i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " <<"LINE:"<<__LINE__<<"  "<< #i <<":"<< i << std::endl

 
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
 
long long pow_mod(long long a, long long b, long long mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  long long x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const long long MOD = 998244353;
const long long MOD = 1e9 + 7;

using ll = long long;
using P = std::pair<ll, ll>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll h,w,a,b;
  std::cin>>h>>w>>a>>b;

  if(h%a==0&&w%b==0){
    std::cout<<"No\n";
    return 0;
  }

  std::cout<<"Yes\n";

  bool flip=false;

  ll n=w,m=b;

  if(w%b==0){
    flip=true;
    n=h;
    m=a;
  }

  std::vector<ll> sum(n+1);

  for(ll i=n;i>0;i--){
    if(i==n)sum[i]=1;
    else if(i+m>n)sum[i]=-1;
    else sum[i]=sum[i+m]+1;
  }

  for(ll i=0;i<=n;i+=m){
    sum[i]=-1*(i/m);
  }

  std::vector<ll> ans(n);
  rep(i,0,n)ans[i]=sum[i+1]-sum[i];

  if(flip){
    rep(i,0,h){
      rep(j,0,w){
        std::cout<<ans[i]<<" ";
      }
      std::cout<<"\n";
    }
  }else{
    rep(i,0,h){
      std::cout<<ans<<"\n";
    }
  }

  return 0;
}