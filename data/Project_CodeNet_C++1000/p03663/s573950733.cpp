#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

bool query(lint n) {
  cout << "? " << n << endl;
  char c; cin >> c;
  return c == 'Y';
}

template<class T> int ord(T n, int p) { return n % p ? 0 : ord(n / p, p) + 1; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint l = 1e9, r = 1e10 - 1;
  while (r - l > 1) {
    lint m = (l + r) / 2;
    if (query(10 * m)) r = m;
    else l = m;
  }
  lint t = 1;
  while (t < 1e13) {
    if (!query(t)) break;
    t *= 10;
  }
  if (t >= 1e12) {
    r = 1;
    while (!query(2 * r)) r *= 10;
  }
  cout << "! " << to_string(r).substr(0, ord(t, 10)) << '\n';
}