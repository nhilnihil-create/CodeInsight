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

#define invll(v, n)                              \
  vector<long long> v(n);                        \
  for (long long i = 0; i < n; i++) cin >> v[i];

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

#include <iomanip>

ll comb(ll n, ll k) {
    if (k > n) return 0LL;
    if (k * 2LL > n) k = n - k;
    if (k == 0LL) return 1LL;

    ll result = n;
    for(ll i = 2LL; i <= k; i++) {
        result *= (n - i + 1LL);
        result /= i;
    }
    return result;
}

void solve() {
    ini(N, A, B);
    invll(v, N);
    sort(v.begin(), v.end(), greater<ll>());

    auto num_vA = (int)count(v.begin(), v.end(), v[A - 1]);
    ll left = 0;
    while (v[left] != v[A - 1]) left++;
    ll right = N - 1;
    while (v[right] != v[A - 1]) right--;

    ll sum = accumulate(&v[0], &v[A], 0LL);
    cout << fixed << setprecision(6) << static_cast<double>(sum) / static_cast<double>(A) << endl;

    ll min_use = A - left;
    ll max_use = left == 0 ? min(num_vA, B) : min_use;
    
    ll ret = 0;
    for (ll i = min_use; i <= max_use; i++) {
        ret += comb(num_vA, i);
    }
    out(ret);
}
