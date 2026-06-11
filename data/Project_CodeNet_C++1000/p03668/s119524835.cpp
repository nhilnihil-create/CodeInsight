#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, l, r) for (int i = (int)(l); i < (int)(r); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T> using V = vector<T>;
using P = pair<int, int>;

/*
 */

int n;
V<int> es[101010];

int dfs(int v, int p){
  int g = 0;
  for(int to : es[v]){
    if(to == p) continue;
    g ^= dfs(to, v) + 1;
  }

  return g;
}

signed main() {
  cin >> n;
  rep(i, 0, n-1){
    int x, y;
    cin >> x >> y;
    x--; y--;
    es[x].emplace_back(y);
    es[y].emplace_back(x);
  }

  cout << (dfs(0, -1) ? "Alice" : "Bob") << endl;

  return 0;
}
