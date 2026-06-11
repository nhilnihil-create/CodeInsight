#line 1 "/mnt/c/Users/leafc/dev/compro/lib/doubling.hpp"
#include <cmath>
#include <vector>

#ifndef DOUBLING
#define DOUBLING
// ダブリングを行う、最初の要素が入った配列を渡すとダブリングしたものを返す
// no_valueには存在しない場合何を入れればいいのかを入れておく
template <class T> std::vector<std::vector<T>> doubling(std::vector<T> &init, T no_value) {
  int size = init.size();
  int doubling_size = std::floor(std::log2(size) + 1);
  std::vector<std::vector<T>> ret(doubling_size, std::vector<T>(size));

  for (int i = 0; i < size; i++) {
    ret[0][i] = init[i];
  }

  for (int k = 0; k < doubling_size - 1; k++) {
    for (int i = 0; i < size; i++) {
      if (ret[k][i] == no_value) {
        ret[k + 1][i] = no_value;
      } else {
        ret[k + 1][i] = ret[k][ret[k][i]];
      }
    }
  }
  return ret;
}
#endif
#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 3 "tmp.cpp"

bool f(int a, int b, int mid, vector<vector<int>> &db) {
  int cur = a;
  int cnt = 0;
  while (mid > 0) {
    if (mid % 2 == 1) {
      cur = db[cnt][cur];
    }
    if (cur >= b)
      return true;
    cnt++;
    mid /= 2;
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vi x(n + 1);
  REP(i, n) { cin >> x[i]; }
  int l;
  cin >> l;

  x[n] = 1e9 + 1;
  vi next(n, n);
  REP(i, n) { next[i] = upper_bound(ALL(x), x[i] + l) - x.begin() - 1; }
  auto db = doubling(next, n);

  int q;
  cin >> q;
  REP(i, q) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b)
      swap(a, b);
    int ok = n;
    int ng = 0;
    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (f(a, b, mid, db)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    cout << ok << endl;
  }
  return 0;
}
