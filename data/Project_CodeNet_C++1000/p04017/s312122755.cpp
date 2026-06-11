#include <bits/stdc++.h>
using namespace std;

int n, l, q;
vector<int> x;
vector<vector<int>> memo, rmemo;

int calc(int lef, int righ, vector<vector<int>>& v);

int main() {
  cin >> n;
  x.resize(n);
  for (auto& p : x) cin >> p;
  cin >> l >> q;
  auto makememo = [] {
    vector<vector<int>> res(n, vector<int>(31, 0));
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < n - 1 && x[j + 1] - x[i] <= l) ++j;
      res[i][0] = j;
    }
    for (int j = 1; j < 31; ++j)
      for (int i = 0; i < n; ++i) res[i][j] = res[res[i][j - 1]][j - 1];
    return res;
  };
  memo = makememo();
  reverse(x.begin(), x.end());
  for (auto& p : x) p = (long long)(1e9) - p;
  rmemo = makememo();
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      --a, --b;
      cout << calc(a, b, memo) << endl;
    } else {
      a = n - a;
      b = n - b;
      cout << calc(a, b, rmemo) << endl;
    }
  }
  return 0;
}
int calc(int lef, int righ, vector<vector<int>>& v) {
  int res = 0;
  while (lef < righ) {
    int id = 0;
    while (v[lef][id] < righ) ++id;
    id = max(id - 1, 0);
    lef = v[lef][id];
    res += 1 << id;
  }
  return res;
}