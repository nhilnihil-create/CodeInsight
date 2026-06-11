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
    ini(n);
    vll a(n);
    rep(i, n) cin >> a[i];

    ll ret1 = 0; 
    ll sum1 = 0;
    bool must_plus = true;
    rep (i, n) {
        sum1 += a[i];
        if (must_plus && sum1 <= 0)  {
            ret1 += 1 - sum1;
            sum1 = 1;
        } else if (!must_plus && sum1 >= 0) {
            ret1 += 1 + sum1;
            sum1 = -1;
        }
        must_plus = !must_plus;
    }
    
    ll ret2 = 0; 
    ll sum2 = 0;
    must_plus = false;
    rep (i, n) {
        sum2 += a[i];
        if (must_plus && sum2 <= 0)  {
            ret2 += 1 - sum2;
            sum2 = 1;
        } else if (!must_plus && sum2 >= 0) {
            ret2 += 1 + sum2;
            sum2 = -1;
        }
        must_plus = !must_plus;
    }

    out(min(ret1, ret2));
}
