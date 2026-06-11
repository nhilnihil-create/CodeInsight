#include <bits/stdc++.h>
using namespace std;
class binary_indexed_tree {
  public:
    int n;
    vector<int> tr;
    binary_indexed_tree (int size) {
      n = size;
      tr.resize(n, 0);
    }
    int size () {
      return n;
    }
    int acm (int i) {
      int ret = 0;
      for (; i >= 0; i &= i + 1, i--){
        ret += tr[i];
      }
      return ret;
    }
    void add (int i, int x) {
      for (; i < n; i |= i + 1) {
        tr[i] += x;
      }
    }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  binary_indexed_tree bit(m + 1);
  vector<vector<pair<int, int>>> itv(m + 1);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    int d = ++r - l;
    bit.add(l, 1);
    bit.add(r, -1);
    itv[d].push_back({l, r});
  }
  vector<int> ret(m + 1, 0);
  int base = 0;
  for (int d = m; d >= 1; d--) {
    ret[d] = base;
    for (int i = 0; i <= m; i += d) {
      ret[d] += bit.acm(i);
    }
    for (auto &nxt : itv[d]) {
      int l = nxt.first;
      int r = nxt.second;
      bit.add(l, -1);
      bit.add(r, 1);
      base++;
    }
  }
  for (int d = 1; d <= m; d++) {
    cout << ret[d] << '\n';
  }
  return 0;
}