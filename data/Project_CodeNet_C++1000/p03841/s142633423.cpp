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
  V< pair<int, int> > x(n);
  for (int i = 0; i < n; i++) {
    int xt; cin >> xt, xt--;
    x[i] = {xt, i};
  }
  sort(x.begin(), x.end());
  V<> a(n * n);
  for (int i = 0; i < n; i++) a[x[i].first] = x[i].second + 1;
  int p = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < x[i].second; j++) {
      while (a[p]) p++;
      a[p] = x[i].second + 1;
    }
  }
  p = n * n - 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n - 1 - x[i].second; j++) {
      while (a[p]) p--;
      a[p] = x[i].second + 1;
    }
  }
  V<> b(n * n), c(n + 1);
  for (int i = 0; i < n * n; i++) b[i] = c[a[i]]++;
  for (int i = 0; i < n; i++) if (b[x[i].first] != x[i].second) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
  for (int i = 0; i < n * n; i++) cout << a[i] << (i != n * n - 1 ? ' ' : '\n');
}