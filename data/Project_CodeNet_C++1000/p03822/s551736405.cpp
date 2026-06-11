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

//非再帰トポロジカルソート 隣接リストを渡す 返り値のサイズがnじゃないならnot DAG
std::vector<ll> topo_sort(std::vector<std::vector<ll>>& graph) {
  ll n = graph.size();
  std::vector<ll> ret, num(n, 0);
  std::queue<ll> que;
  for(ll i=0;i<n;i++){
    for (ll j : graph[i]) num[j]++;
  }
  for (ll i = 0; i < n; i++) {
    if (num[i] == 0) que.push(i);
  }
  while (!que.empty()) {
    ll u = que.front();
    que.pop();
    ret.push_back(u);
    for (ll i : graph[u]) {
      num[i]--;
      if (num[i] == 0) que.push(i);
    }
  }

  return ret;
}
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n;
  std::cin>>n;

  std::vector<std::vector<ll>> graph(n);

  rep(i,1,n){
    ll a;
    std::cin>>a;

    a--;
    graph[a].push_back(i);
  }

  std::vector<ll> topo=topo_sort(graph),depth(n,MOD);

  for(ll i=n-1;i>=0;i--){
    ll now=topo[i];

    ll value=0;
    std::vector<ll> temp;
    for(ll next:graph[now])temp.push_back(depth[next]);

    std::sort(all(temp));

    rep(i,0,temp.size()){
      chmax(value,temp[i]+temp.size()-i);
    }

    depth[now]=value;
  }

  std::cout<<depth[0];

  return 0;
}