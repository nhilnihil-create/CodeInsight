#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, l, t; cin >> n >> l >> t;
  V<lint> x(n), w(n); for (int i = 0; i < n; i++) cin >> x[i] >> w[i];
  V<lint> res(n);
  for (int i = 0; i < n; i++) res[i] = ((x[i] + (3 - 2 * w[i]) * t) % l + l) % l;
  sort(res.begin(), res.end());
  lint c = 0;
  for (int i = 1; i < n; i++) if (w[i] != w[0]) {
    c += 2 * t / l + (w[0] == 1 ? (x[i] - x[0] < 2 * t % l) : (l - x[i] + x[0] <= 2 * t % l));
  }
  c %= n;
  int s;
  for (int i = 0; i < n; i++) if (res[i] == ((x[0] + (3 - 2 * w[0]) * t) % l + l) % l) {
    s = i;
    break;
  }
  for (int i = 0; i < n; i++) cout << res[(w[0] == 1 ? i - c + s + n : i + c + s) % n] << '\n';
}