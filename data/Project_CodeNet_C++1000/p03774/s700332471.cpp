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

ll l1_dist(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

void solve() {
    ini(N, M);
    vll a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];
    vll c(M), d(M);
    rep(i, M) cin >> c[i] >> d[i];

    rep(i, N) {
        ll ret = -1;
        ll min_dist = 1LL << 62; 
        rep(j, M) {
            ll dist = l1_dist(a[i], b[i], c[j], d[j]);
            if (min_dist > dist) {
                 min_dist = dist;
                 ret = j;
            }
        }
        out(ret + 1);
    }
}
