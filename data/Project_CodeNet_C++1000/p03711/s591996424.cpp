#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
  int sz;
  vector<int> par, size_;
public:
  UnionFind() {}
  UnionFind(int n) : sz(n), par(sz), size_(sz, 1) {
    iota(par.begin(), par.end(), 0);
  }
  int root(int x) {
    if (par.at(x) == x) return x;
    else return par.at(x) = root(par.at(x));
  }
  void unit(int x,int y) {
    x = root(x), y = root(y);
    if (x == y) return;
    if (size_.at(x) < size_.at(y)) swap(x, y);
    par.at(y) = x;
    size_.at(x) += size_.at(y);
  }
  int size(int x) {
    x = root(x);
    return size_.at(x);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

int main() {
  UnionFind UF(13);
  vector<int> V1 = {1,3,5,7,8,10,12};
  vector<int> V2 = {4,6,9,11};
  for (int i = 0; i < V1.size(); i++) {
    if (i) UF.unit(V1.at(i - 1), V1.at(i));
  }
  for (int i = 0; i < V2.size(); i++) {
    if (i) UF.unit(V2.at(i - 1), V2.at(i));
  }
  int x, y;
  cin >> x >> y;
  cout << ((UF.same(x, y)) ? "Yes" : "No") << "\n";
}