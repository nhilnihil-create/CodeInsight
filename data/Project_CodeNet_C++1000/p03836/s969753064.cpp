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

void solve2(int tx) {
    rep(i, tx) cout << "R";
    
    cout << "U";
    rep(i, tx) cout << "L";
    cout << "D";

    cout << "D";
    rep(i, tx) cout << "R";
    cout << "U";

    cout << "R" << "D" << "D";
    rep(i, tx + 2) cout << "L";
    cout << "U" << "U" << "R";
}

void solve3(int ty) {
    rep(i, ty) cout << "U";
    
    cout << "R";
    rep(i, ty) cout << "D";
    cout << "L";

    cout << "L";
    rep(i, ty) cout << "U";
    cout << "R";

    cout << "U" << "R" << "R";
    rep(i, ty + 2) cout << "D";
    cout << "L" << "L" << "U";
}

void solve1(int tx, int ty) {
    rep(i, ty) cout << "U";
    rep(i, tx) cout << "R";

    rep(i, ty) cout << "D";
    rep(i, tx) cout << "L";

    cout << "L";
    rep(i, ty + 1) cout << "U";
    rep(i, tx + 1) cout << "R";
    cout << "D";

    cout << "R";
    rep(i, ty + 1) cout << "D";
    rep(i, tx + 1) cout << "L";
    cout << "U";
}

void solve() {
    ini(sx, sy, tx, ty);
    tx -= sx;
    ty -= sy;

    if (ty == 0) {
        solve2(tx);
    } else if (tx == 0) {
        solve3(ty);
    } else {
        solve1(tx, ty);
    }
    out();
}
