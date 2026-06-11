#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//const ll INF = (ll)1e18 + 1;

struct edge{
  ll to;
  ll cost;
};
using Graph = vector<vector<edge>>;
int main(){
  ll N; cin >> N;
  Graph G(N);
  rep(i, N - 1){
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    G[a].push_back(edge {b, c});
    G[b].push_back(edge {a, c});
  }
  ll Q, K; cin >> Q >> K;
  K--;

  vector<ll> d(N, INF);
  d[K] = 0;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(make_pair(0, K));
  while (!que.empty()){
    P p = que.top(); que.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    for (auto e: G[v]){
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(make_pair(d[e.to], e.to));
      }
    }
  }

  rep(i, Q){
    ll x, y; cin >> x >> y;
    x--, y--;
    cout << d[x] + d[y] << endl;
  }
}
