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

void solve() {
  inl(H, W);

  ll res = 1LL << 62;
  for (int w = 1; w < W; w++) {
    vll S;
    S.push_back(H * w);

    ll w2 = (W - w) / 2;
    ll w3 = W - w - w2;
    S.push_back(H * w2);
    S.push_back(H * w3);
    sort(S.begin(), S.end());
    if (S.back() - S.front() < res)
      res = S.back() - S.front();

    S.clear();
    S.push_back(H * w);
    ll h2 = H / 2;
    ll h3 = H - h2;
    S.push_back(h2 * (W - w));
    S.push_back(h3 * (W - w));
    sort(S.begin(), S.end());
    if (S.back() - S.front() < res)
      res = S.back() - S.front();
  }

  swap(H, W);
  for (int w = 1; w < W; w++) {
    vll S;
    S.push_back(H * w);

    ll w2 = (W - w) / 2;
    ll w3 = W - w - w2;
    S.push_back(H * w2);
    S.push_back(H * w3);
    sort(S.begin(), S.end());
    if (S.back() - S.front() < res)
      res = S.back() - S.front();

    S.clear();
    S.push_back(H * w);
    ll h2 = H / 2;
    ll h3 = H - h2;
    S.push_back(h2 * (W - w));
    S.push_back(h3 * (W - w));
    sort(S.begin(), S.end());
    if (S.back() - S.front() < res)
      res = S.back() - S.front();
  }

  out(res);
}
