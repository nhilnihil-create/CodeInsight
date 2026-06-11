#include <bits/stdc++.h>
using namespace std;

class UnionFindTree {
private:
  vector<int> par;
  vector<int> depth;

public:
  UnionFindTree(int n) {
    for (int i = 0; i < n; i++) {
      par.push_back(i);
      depth.push_back(0);
    }
  }

  int find(int x) {
    if (par[x] == x) {
      return x;
    } else {
      return par[x] = find(par[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;

    if (depth[x] < depth[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (depth[x] == depth[y])
        depth[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    int n, k, l;
    cin >> n >> k >> l;
    UnionFindTree road = UnionFindTree(n+1), rail = UnionFindTree(n+1);
    for(int i=0;i<k;++i){
        int p, q;
        cin >> p >> q;
        road.unite(p, q);
    }
    for(int i=0;i<l;++i){
        int r, s;
        cin >> r >> s;
        rail.unite(r, s);
    }
    map<pair<int, int>, int> mp;
    for(int i=1;i<=n;++i){
        mp[make_pair(road.find(i), rail.find(i))]++;
    }
    for(int i=1;i<=n;++i){
        cout << mp[make_pair(road.find(i), rail.find(i))];
        if(i == n)cout << endl;
        else cout << " ";
    }

  return 0;
}
