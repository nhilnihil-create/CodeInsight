#include <algorithm>
#include <bitset>
#include <cassert>
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

template <class T>
vector<T> sumup(const vector<T>& a) {
  int N = a.size();
  vector<T> res(N + 1);
  for (int i = 0; i < N; i++) res[i + 1] = res[i] + a[i];
  return res;
}

template <class T>
ll invs(vector<T>& A) {
  ll res = 0;
  int N = A.size();
  if (N > 1) {
    vector<T> L(A.begin(), A.begin() + N / 2);
    vector<T> R(A.begin() + N / 2, A.end());
    res += invs(L);
    res += invs(R);
    for (int i = 0, j = 0; i < L.size(); i++) {
      while (j < R.size() && R[j] < L[i]) ++j;
      res += j;
    }
    merge(L.begin(), L.end(), R.begin(), R.end(), A.begin());
  }
  return res;
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  int N;
  ll K;
  while (cin >> N >> K) {
    vector<ll> A(N);
    for (ll& x : A) cin >> x;
    auto S = sumup(A);
    for (int i = 0; i < S.size(); i++) S[i] -= i * K;
    ll res = 1ll * N * (N + 1) / 2 - invs(S);
    cout << res << endl;
  }
  return 0;
}
