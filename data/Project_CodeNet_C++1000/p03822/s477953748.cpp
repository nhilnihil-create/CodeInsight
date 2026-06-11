#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}

using Graph = vector<vector<int>>;
Graph G;

int dfs(int v) {
  V depth;
  for (auto nv : G[v]) {
    depth.push_back(dfs(nv));
  }
  sort(all(depth));
  reverse(all(depth));
  int res = 0;
  rep(i, depth.size()) chmax(res, depth[i]+i);
  return res+1;
}

int main() {
  int N; cin >> N;
  G = Graph(N);
  for (int i = 0; i < N-1; i++) {
    int a;
    cin >> a;
    a--;
    G[a].push_back(i+1);
  }
  int ans = dfs(0)-1;
  cout << ans << endl;
  return 0;
}
