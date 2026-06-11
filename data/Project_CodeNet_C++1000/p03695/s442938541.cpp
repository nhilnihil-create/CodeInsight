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

void solve() {
  ini(N);
  vll a(N);
  rep(i, N) cin >> a[i];

  vll bound = {0, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200};
  vll count(bound.size());
  rep(i, N) {
    rep(j, bound.size() - 1) {
      if (bound[j] <= a[i] && a[i] < bound[j + 1])
        count[j]++;
    }
    if (bound.back() <= a[i])
      count.back()++;
  }

  ll colors =
      count_if(count.begin(), count.end() - 1, [](auto x) { return x > 0; });
  out(max(1LL, colors), colors + count.back());
}
