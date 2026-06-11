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

using P = pair<int, int>;

bool check(const vec<int, 2>& A, const vec<int, 2>& B, int L) {
  int N = A.size(), M = A[0].size();
  vector<set<P>> top(A.size());
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) top[i].insert(P(j, A[i][j]));
  }
  int rem = M;
  while (rem > 0) {
    vector<int> cnt(M, 0);
    for (int i = 0; i < N; i++) {
      auto p = *top[i].begin();
      ++cnt[p.snd];
    }
    bool cont = false;
    for (int k = 0; k < M; k++) {
      if (cnt[k] > L) {
        cont = true;
        --rem;
        for (int i = 0; i < N; i++) top[i].erase(P(B[i][k], k));
      }
    }
    if (!cont) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef DEBUG
  ifstream cin("in.txt");
#endif
  int N, M;
  while (cin >> N >> M) {
    vec<int, 2> A = make_v(N, M, -1);
    vec<int, 2> B = make_v(N, M, -1);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> A[i][j];
        --A[i][j];
        B[i][A[i][j]] = j;
      }
    }
    int fail = 0, pass = N;
    while (pass - fail > 1) {
      int L = (fail + pass) / 2;
      if (check(A, B, L)) {
        pass = L;
      } else {
        fail = L;
      }
    }
    cout << pass << endl;
  }
  return 0;
}
