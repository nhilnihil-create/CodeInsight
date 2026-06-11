#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class H> void rsz(V<T> &v, H h) { v.resize(h); }
template<class T, class H, class... R> void rsz(V<T> &v, H h, R... r) { v.resize(h); for (auto&& i : v) rsz(i, r...); }
int n;
int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  cin >> n;
  int m = 1; while (m * (m + 1) / 2 < n) m++;
  for (int i = 1; i < m + 1; i++) {
    if (i == m * (m + 1) / 2 - n) continue;
    cout << i << '\n';
  }
}