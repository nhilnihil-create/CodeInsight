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

int main() {
  int N, M; cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  V path;
  vector<bool> chosen(N, false);
  path.push_back(0);
  chosen[0] = true;

  bool next = true;
  while (next) {
    next = false;
    for (auto e : G[path.back()]) {
      if (!chosen[e]) {
        path.push_back(e);
        chosen[e] = true;
        next = true;
        break;
      }
    }
  }

  reverse(all(path));
  
  next = true;
  while (next) {
    next = false;
    for (auto e : G[path.back()]) {
      if (!chosen[e]) {
        path.push_back(e);
        chosen[e] = true;
        next = true;
        break;
      }
    }
  }

  cout << path.size() << endl;
  for (auto e : path) {
    cout << (e+1) << " ";
  }
  cout << endl;
  return 0;
}
