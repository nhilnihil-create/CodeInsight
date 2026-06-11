#include <algorithm>
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
/* clang-format on */

int main() {
  int N;
  while (cin >> N) {
    vector<ll> A;
    for (int i = 0; i < N; i++) {
      char op = '+';
      if (i > 0) cin >> op;
      ll x;
      cin >> x;
      if (op == '-') x = -x;
      A.push_back(x);
    }
    vector<int> minus;
    for (int i = 0; i < N; i++) {
      if (A[i] < 0) minus.push_back(i);
    }
    vector<ll> sum(N + 1, 0), asum(N + 1, 0);
    for (int i = 0; i < N; i++) {
      sum[i + 1] = sum[i] + A[i];
      asum[i + 1] = asum[i] + abs(A[i]);
    }
    ll res = sum[N];
    for (int i = 0; i + 1 < minus.size(); i++) {
      int a = minus[i], b = minus[i + 1];
      res = max(res, sum[a] - (asum[b] - asum[a]) + (asum[N] - asum[b]));
    }
    cout << res << endl;
  }
  return 0;
}
