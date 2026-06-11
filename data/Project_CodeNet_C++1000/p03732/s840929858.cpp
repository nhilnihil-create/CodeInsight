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
  inl(N, W);

  vll v[4];
  inl(base_weight);
  v[0].resize(1);
  cin >> v[0][0];

  rep(i, N - 1) {
    inl(w, v1);
    v[w - base_weight].push_back(v1);
  }

  vll acc_sum[4];
  rep(i, 4) {
    sort(v[i].begin(), v[i].end(), greater<ll>());
    acc_sum[i].resize(v[i].size() + 1);
    acc_sum[i][0] = 0;
    rep(j, v[i].size()) acc_sum[i][j + 1] = acc_sum[i][j] + v[i][j];
  }

  ll ret = 0;
  rep(i, v[3].size() + 1) {
    rep(j, v[2].size() + 1) {
      rep(k, v[1].size() + 1) {
        ll rest = W - (i * (base_weight + 3) + j * (base_weight + 2) +
                       k * (base_weight + 1));
        if (rest < 0)
          break;
        ll num = min(rest / base_weight, (ll)(v[0].size()));

        ll value =
            acc_sum[3][i] + acc_sum[2][j] + acc_sum[1][k] + acc_sum[0][num];
        if (ret < value)
          ret = value;
      }
    }
  }

  out(ret);
}
