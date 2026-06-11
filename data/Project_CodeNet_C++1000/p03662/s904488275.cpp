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
#define debug(i) std::cout << i << "\n"

//const ll MOD = 998244353;
const ll MOD = 1e9+7;

//累乗(mod付き)
ll pow_mod(ll a, ll b, ll mod) {
  if (a % mod == 0) {
    return 0;
  }

  ll x = 1;

  while (b > 0) {
    if (b & 1) {
      x = (x * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return x;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n;
  std::cin>>n;
  std::vector<std::vector<ll>> graph(n,std::vector<ll>());
  rep(i,1,n){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  std::vector<ll> start(n,LLONG_MAX),goal(n,LLONG_MAX);

  std::queue<ll> que;
  que.push(0);
  start[0]=0;

  while(que.size()){
    ll p=que.front();que.pop();

    rep(i,0,graph[p].size()){
      if(start[graph[p][i]]==LLONG_MAX){
        start[graph[p][i]]=start[p]+1;
        que.push(graph[p][i]);
      }
    }
  }

  que.push(n-1);
  goal[n-1] = 0;

  while (que.size()) {
    ll p = que.front();
    que.pop();

    rep (i, 0, graph[p].size()) {
      if (goal[graph[p][i]] == LLONG_MAX) {
        goal[graph[p][i]] = goal[p] + 1;
        que.push(graph[p][i]);
      }
    }
  }

  ll count=0;

  rep(i,0,n)if(start[i]<=goal[i])count++;

  if(count>n/2)std::cout<<"Fennec";
  else std::cout<<"Snuke";

  return 0;
}