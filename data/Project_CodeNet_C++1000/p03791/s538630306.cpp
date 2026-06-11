#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr lint mod = 1e9 + 7;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> x(n); for (int i = 0; i < n; i++) cin >> x[i];
  lint res = 1;
  int s = 0;
  for (int i = 1; i < n; i++) {
    (res *= i + 1 - s) %= mod;
    if (x[i] < 2 * (i - s) + 1) s++;
  }
  cout << emod(res) << '\n';
}