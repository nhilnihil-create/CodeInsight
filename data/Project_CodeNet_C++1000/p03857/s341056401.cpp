#include <bits/stdc++.h>
using namespace std;

struct Unionfind {
  // tree number
  vector<int> par;
  // tree rank
  vector<int> treerank;
  // constructor
  Unionfind(int n = 1) { stree(n + 1); }
  // make and initialization
  void stree(int n = 1) {
    par.resize(n);
    treerank.resize(n);
    for(int i = 0; i < n; ++i) {
      par[i] = i;
      treerank[i] = 0;
    }
  }
  // search root
  int root(int x) {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  // is same?
  bool issame(int x, int y) { return root(x) == root(y); }

  // add
  // already added, return 0
  bool uni(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return 0;
    if(treerank[x] < treerank[y])
      par[x] = y;
    else if(treerank[y] < treerank[x])
      par[y] = x;
    else {
      par[y] = x;
      ++treerank[x];
    }
    return 1;
  }
};
int n, l, k;
Unionfind uf[2];
map<pair<int, int>, int> mp;

void solve();

int main() {
  cin >> n >> k >> l;
  uf[0] = uf[1] = Unionfind(n + 1);
  for(int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    uf[0].uni(x, y);
  }
  for(int i = 0; i < l; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    uf[1].uni(x, y);
  }
  for(int i = 0; i < n; ++i)
    ++mp[make_pair(uf[0].root(i), uf[1].root(i))];
  for(int i = 0; i < n; ++i) {
    cout << mp[make_pair(uf[0].root(i), uf[1].root(i))];
    if(i != n - 1) cout << " ";
  }
  cout << endl;
  return 0;
}
