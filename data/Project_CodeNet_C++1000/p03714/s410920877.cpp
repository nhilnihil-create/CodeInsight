#include <algorithm>
#include <climits>
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

void solve() {
  inl(N);
  vll a(3 * N);
  rep(i, 3 * N) cin >> a[i];

  vll plus(N + 1, 0LL);
  plus[0] = accumulate(&a[0], &a[N], 0LL);
  priority_queue<ll, vll, greater<ll>> que;
  rep(i, N) que.push(a[i]);
  rep(i, N) {
    que.push(a[N + i]);
    auto min = que.top();
    que.pop();
    plus[i + 1] = plus[i] + a[N + i] - min;
  }

  vll minus(N + 1, 0LL);
  minus[0] = accumulate(&a[2 * N], &a[3 * N], 0LL);
  priority_queue<ll> que2;
  rep(i, N) que2.push(a[2 * N + i]);
  rep(i, N) {
    que2.push(a[2 * N - i - 1]);
    auto max = que2.top();
    que2.pop();
    minus[i + 1] = minus[i] + a[2 * N - i - 1] - max;
  }

  ll ret = plus[0] - minus[0];
  rep(i, N + 1) {
    auto diff = plus[i] - minus[N - i];
    if (diff > ret)
      ret = diff;
  }

  out(ret);
}
