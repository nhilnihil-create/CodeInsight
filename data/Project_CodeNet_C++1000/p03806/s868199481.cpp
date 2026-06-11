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
    ini(N, Ma, Mb);
    vector<int> a(N), b(N), c(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(401, vector<int>(401, 1 << 20)));
    dp[0][0][0] = 0;

    rep(i, N) {
        for (int j = 0; j <= 400; j++) {
            for (int k = 0; k <= 400; k++) {
                if (j >= a[i] && k >= b[i])
                    dp[i + 1][j][k] = min(dp[i][j][k], dp[i][j - a[i]][k - b[i]] + c[i]);
                else
                    dp[i + 1][j][k] = dp[i][j][k];
            }
        }
    }

    int ret = 1 << 20;
    for (int i = 1; i * Ma <= 400 && i * Mb <= 400; i++)
        ret = min(ret, dp[N][i * Ma][i * Mb]);

    if (ret < (1 << 20))
        out(ret);
    else
        out(-1);
}
