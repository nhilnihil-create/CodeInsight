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

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N;
ll A[101010];
map<ll, ll> mp;

long long modpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  cin >> N;
  rep(i, 0, N) {
    cin >> A[i];
    ++mp[A[i]];
  }

  if (N % 2 == 1) {
    for (ll i = N - 1; i >= 2; i -= 2) {
      if (mp[i] != 2) {
        cout << 0;
        return 0;
      }
    }
    if (mp[0] != 1) {
      cout << 0;
      return 0;
    }
    cout << modpow(2, N / 2);
  } else {
    for (ll i = N - 1; i >= 1; i -= 2) {
      if (mp[i] != 2) {
        cout << 0;
        return 0;
      }
    }
    cout << modpow(2, N / 2);
  }
}
