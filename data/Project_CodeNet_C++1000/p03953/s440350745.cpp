#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> x(n); for (int i = 0; i < n; i++) cin >> x[i];
  int m; cin >> m;
  lint k; cin >> k;
  V<> a(m); for (int i = 0; i < m; i++) cin >> a[i], a[i]--;
  V<> p(n - 1); iota(p.begin(), p.end(), 0);
  for (int i = 0; i < m; i++) swap(p[a[i] - 1], p[a[i]]);
  V<> to(n - 1);
  V<bool> chk(n - 1);
  for (int i = 0; i < n - 1; i++) if (!chk[i]) {
    V<> b;
    chk[i] = true;
    b.push_back(i);
    int t = p[i];
    while (t != i) {
      chk[t] = true;
      b.push_back(t);
      t = p[t];
    }
    lint c = b.size();
    for (int i = 0; i < c; i++) to[b[i]] = b[(i + k) % c];
  }
  V<lint> d(n - 1);
  for (int i = 0; i < n - 1; i++) d[i] = x[to[i] + 1] - x[to[i]];
  for (int i = 0; i < n - 1; i++) x[i + 1] = x[i] + d[i];
  for (int i = 0; i < n; i++) cout << x[i] << '\n';
}