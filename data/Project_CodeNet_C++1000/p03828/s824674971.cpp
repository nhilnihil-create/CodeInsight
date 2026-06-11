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

const ll MOD = 1000000007;

void solve() {
    ini(N);

    vector<bool> is_prime(1001, true);
    is_prime[0] = is_prime[1] = false;
    unordered_map<int, ll> primes;
    for (int i = 2; i <= 1000; i++) {
        if (!is_prime[i])
            continue;

        primes.insert(make_pair(i, 0LL));
        for (int j = 2; i * j <= 1000; j++)
            is_prime[i * j] = false;
    }

    for (int i = 1; i <= N; i++) {
        int tmp = i;
        for (auto& p : primes) {
            while (tmp % p.first == 0) {
                tmp /= p.first;
                p.second++;
            }
            if (tmp == 1)
                break;
        }
    }

    ll ret = 1LL;
    for (auto p : primes)
        ret = (ret * (p.second + 1)) % MOD;

    out(ret);
}
