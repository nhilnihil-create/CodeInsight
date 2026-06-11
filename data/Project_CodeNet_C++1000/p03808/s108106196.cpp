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

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl
 
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
inline bool chmin(T1& a,T2 b){return a<b && (a=b,true);}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
 
  ll n;
  std::cin>>n;

  std::vector<ll> a(n);
  rep(i,0,n)std::cin>>a[i];

  ll sum=0;
  rep(i,0,n)sum+=a[i];

  if(sum%(n*(n+1)/2)!=0){
    std::cout<<"NO\n";
    return 0;
  }

  sum=sum/(n*(n+1)/2);

  a.push_back(a[0]);

  rep(i,0,n){
    if((a[i+1]-a[i]-sum>0)||(sum+a[i]-a[i+1])%n!=0){
      std::cout<<"NO\n";
      return 0;
    }
  }

  std::cout<<"YES\n";
 
  return 0;
}