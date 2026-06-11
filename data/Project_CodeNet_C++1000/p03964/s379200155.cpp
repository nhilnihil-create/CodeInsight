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

int main() {
  cin >> N;
  ll ct, ca;
  cin >> ct >> ca;
  ll csum = ct + ca;

  rep(i, 0, N - 1) {
    ll t, a;
    cin >> t >> a;
    ll sum = t + a;
    if (csum % sum != 0) {
      csum = csum - csum % sum + sum;
    }

    ll nt = csum / sum * t;

    if (nt < ct) {
      ll diff = ct - nt;
      ll mul = (diff + t - 1) / t;
      csum += sum * mul;
    }

    ll na = csum / sum * a;
    if (na < ca) {
      ll diff = ca - na;
      ll mul = (diff + a - 1) / a;
      csum += sum * mul;
    }

    ct = csum / sum * t;
    ca = csum / sum * a;
  }
  cout << csum << endl;
}
