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

// i 枚目が必要かどうか
bool is_needed(vll& a, ll target, int K) {
    swap(a.back(), a.at(target));

    vector<vector<bool>> s(a.size(), vector<bool>(K, false));
    s[0][0] = true;
    rep(i, a.size() - 1) {
        for(ll j = 0; j < K; j++)
            if (j >= a[i]) 
                s[i + 1][j] = s[i][j - a[i]] || s[i][j];
            else
                s[i + 1][j] = s[i][j];
    }

    bool ret = false;
    for (ll j = max(K - a.back(), 0LL); j <= K - 1; j++)
        if (s.back()[j]) ret = true;

    swap(a.back(), a.at(target));

    return ret;
}

void solve() {
    ini(N, K);
    vll a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());

    if (is_needed(a, 0, K))
        out(0);
    else if (!is_needed(a, a.size() - 1, K))
        out(a.size());
    else {
        ll left = 0, right = a.size() - 1;
        while (left + 1 != right) {
            ll mid = (left + right) / 2;
            if (is_needed(a, mid, K))
                right = mid;
            else
                left = mid;
        }
        out(right);
    }
}
