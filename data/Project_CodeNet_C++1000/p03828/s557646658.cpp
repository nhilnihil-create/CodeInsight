#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    res[n]++;
  }
  return res;
}

ll N;
map<ll, ll> facs;

int main() {
  cin >> N;
  if (N == 1) {
    cout << 1;
    return 0;
  }
  repe(i, 2, N) {
    auto mp = prime_factor(i);
    for (auto e : mp) {
      facs[e.first] += e.second;
    }
  }

  ll ans = 1;
  for (auto e : facs) {
    ans *= e.second + 1;
    ans %= MOD;
  }
  cout << ans;
}
