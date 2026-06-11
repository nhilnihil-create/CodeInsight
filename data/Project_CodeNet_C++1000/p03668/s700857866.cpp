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
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  ll x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

ll grundy(ll now,ll par,std::vector<std::vector<ll>>& graph){
  ll val=0;
  for(ll next:graph[now]){
    if(next!=par){
      val^=(1+grundy(next,now,graph));
    }
  }

  return val;
}
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<std::vector<ll>> graph(n);

  rep(i,0,n-1){
    ll x,y;
    std::cin>>x>>y;
    x--;y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  ll ans=0;

  for(ll next:graph[0]){
    ans^=(1+grundy(next,0,graph));
  }

  if(ans==0)std::cout<<"Bob";
  else std::cout<<"Alice";
 
  return 0;
}