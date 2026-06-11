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
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

struct edge{
  ll to;
  ll cost;
  edge(ll to, ll cost): to(to), cost(cost) {}
};
int N, Q, K;
vector<vector<edge>> G;
ll dist[101010];
void rec(int v, ll sum, int p = -1){
  dist[v] = sum;
  for (auto nv: G[v]){
    if (nv.to == p) continue;
    rec(nv.to, sum + nv.cost, v);
  }
}

int main(){
  cin >> N;
  G.resize(N);
  rep(i, N - 1){
    ll a, b, c; cin >> a >> b >> c;
    a--, b--;
    G[a].emplace_back(edge(b, c));
    G[b].emplace_back(edge(a, c));
  }
  cin >> Q >> K; K--;
  rec(K, 0, -1);
  rep(i, Q){
    ll x, y; cin >> x >> y;
    x--, y--;
    cout << dist[x] + dist[y] << endl;
  }
}
