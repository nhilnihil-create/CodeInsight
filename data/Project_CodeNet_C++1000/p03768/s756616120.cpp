#include <cassert>
#include "limits.h"
#include <limits>
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
using P = std::pair<long long,long long>;



int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,m;
  std::cin>>n>>m;

  std::vector<std::vector<ll>> graph(n);

  rep(i,0,m){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<std::vector<ll>> color(n,std::vector<ll>(11,MOD));

  struct Query{
    ll v,d,col;
    Query(ll a,ll b,ll c):v(a),d(b),col(c){}
  };

  std::vector<Query> query;

  ll q;
  std::cin>>q;

  rep(i,0,q){
    ll v,d,c;
    std::cin>>v>>d>>c;
    v--;
    query.emplace_back(Query(v,d,c));
  }

  std::reverse(all(query));

  rep(i,0,q){
    chmin(color[query[i].v][query[i].d],i);
  }

  for(ll i=10;i>0;i--){
    rep(j,0,n){
      for(ll e:graph[j]){
        chmin(color[e][i-1],color[j][i]);
      }
      chmin(color[j][i-1],color[j][i]);
    }
  }

  rep(i,0,n){
    if(color[i][0]!=MOD)std::cout<<query[color[i][0]].col<<"\n";
    else std::cout<<0<<"\n";
  }

  return 0;
}