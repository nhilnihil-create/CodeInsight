#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int h, w, d; cin >> h >> w >> d;
  if (d & 1) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) cout << (i + j & 1 ? 'R' : 'Y');
      cout << '\n';
    }
  } else {
    string s = "RYBG";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int x = (i + w - j) % (2 * d) / d;
        int y = (i + w + j) % (2 * d) / d;
        cout << s[2 * x + y];
      }
      cout << '\n';
    }
  }
}