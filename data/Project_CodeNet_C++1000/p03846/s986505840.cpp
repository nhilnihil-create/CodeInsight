#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vll = vector<ll>;

void solve();

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}

#define ini(...)   \
  int __VA_ARGS__; \
  in(__VA_ARGS__)

#define inl(...)  \
  ll __VA_ARGS__; \
  in(__VA_ARGS__)

#define ins(...)      \
  string __VA_ARGS__; \
  in(__VA_ARGS__);

void in() {}
template <typename T, class... U>
void in(T& t, U&... u) {
  cin >> t;
  in(u...);
}

void out() {
  cout << endl;
}
template <typename T, class... U>
void out(const T& t, const U&... u) {
  cout << t;
  if (sizeof...(u))
    cout << " ";
  out(u...);
}

#define rep(i, n) for (long long i = 0; i < n; i++)

void solve();
#ifndef ONLINE_JUDGE
#include "./lib.hpp"
#endif

const ll MOD = 1000000007;

void solve() {
    ini(N);
    vll A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());
    rep(i, N / 2) {
        if (A[2 * i] != N - 2 * i - 1 || A[2 * i + 1] != N - 2 * i - 1) {
            out(0);
            return;
        }
    }
    if (N % 2 == 1 && A[N - 1] != 0) {
        out(0);
        return;
    }

    ll ret = 1;
    rep(i, N / 2)
        ret = (ret * 2) % MOD;
    out(ret);
}
