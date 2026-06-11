/**
 *    author:  tourist
 *    created: 15.01.2020 16:02:44       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> at(m + 2);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    at[l].push_back(r);
    at[r + 1].push_back(~l);
  }
  vector<vector<int>> divs(m + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      divs[j].push_back(i);
    }
  }
  vector<int> ans(m + 1);
  fenwick<int> fenw(m + 1);
  for (int i = 1; i <= m; i++) {
    for (int j : at[i]) {
      if (j >= 0) {
        fenw.modify(i, 1);
      } else {
        fenw.modify(~j, -1);
      }
    }
    for (int j : divs[i]) {
      ans[j] += fenw.get(i) - fenw.get(i - j);
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
