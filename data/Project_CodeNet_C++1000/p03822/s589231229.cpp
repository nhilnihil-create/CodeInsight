#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

int main() {
#ifdef DEBUG
  ifstream cin("in.txt");
#endif
  int N;
  while (cin >> N) {
    vec<int, 2> G(N);
    for (int i = 1; i < N; i++) {
      int a;
      cin >> a;
      --a;
      G[a].push_back(i);
    }
    function<int(int)> dfs = [&](int v) {
      vector<int> ch;
      for (int u : G[v]) {
        ch.push_back(dfs(u));
      }
      sort(ch.rbegin(), ch.rend());
      int res = 0;
      for (int i = 0; i < ch.size(); i++) chmax(res, ch[i] + i + 1);
      return res;
    };
    cout << dfs(0) << endl;
  }
  return 0;
}
