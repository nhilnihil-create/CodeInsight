#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Segment-Tree
struct SegmentTree {
  int n;
  vector<int> dat, lazy;
  
  // Constructor
  SegmentTree(int _n) {
    init(_n);
  }
  
  // 初期化
  void init(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    dat.resize(2 * n - 1, 0);
    lazy.resize(2 * n - 1, 0);
  }
  
  // i番目の値を1加算
  void update(int i, int x) {
    i += n - 1; // 葉のノード
    dat[i]++;
    while (i > 0) { // 更新
      i = (i - 1) / 2;
      dat[i] = dat[2 * i + 1] + dat[2 * i + 2];
    }
  }
  
  // k番目の値を更新(RUQ)
  void eval(int k) {
    if (lazy[k] == 0) return;
    if (k < n - 1) {
      lazy[2 * k + 1] = lazy[k];
      lazy[2 * k + 2] = lazy[k];
    }
    dat[k] = lazy[k];
    lazy[k] = 0;
  }
  
  // 区間[a, b)の値をxに変更(RUQ)
  void update(int a, int b, int x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    eval(k);
    if (a <= l && r <= b) {
      lazy[k]++;
      eval(k);
    }
    else if (a < r && l < b) {
      update(a, b, x, 2 * k + 1, l, (l + r) / 2);
      update(a, b, x, 2 * k + 1, (l + r) / 2, r);
      dat[k] = dat[2 * k + 1] + dat[2 * k + 2];
    }
  }
  
  // [a, b)の最小値
  // k:ノードの番号 [l, r)がkに対応づいている
  // query(a, b, 0, 0, n)と呼ぶ
  int query(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    if (r <= a || b <= l) return 0;
    eval(k); // RUQ
    if (a <= l && r <= b) return dat[k];
    else {
      int vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      int vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return vl + vr;
    }
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
    a.at(i) -= k;
  }
  
  vector<ll> x(n + 1);
  for (int i = 1; i <= n; i++) {
    x.at(i) = a.at(i - 1);
    x.at(i) += x.at(i - 1);
  }
  
  set<ll> s;
  for (int i = 0; i <= n; i++) s.insert(x.at(i));
  
  vector<ll> y;
  for (auto i : s) y.emplace_back(i);
  
  SegmentTree st(s.size());
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    auto it = lower_bound(y.begin(), y.end(), x.at(i)) - y.begin();
    ans += st.query(0, it + 1);
    st.update(it, 1);
  }
  
  cout << ans << '\n';
}