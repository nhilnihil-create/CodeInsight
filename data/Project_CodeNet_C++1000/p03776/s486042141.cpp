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
const long long MINF = LLONG_MIN;

// -------------------------------------------------------
const int MAX = 1010101;

long long binom[55][55];

void binom_init() {
  binom[0][0] = 1;
  binom[1][0] = 1;
  binom[1][1] = 1;

  for (int i = 2; i <= 50; ++i) {
    binom[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
  }
}

ll N, A, B;
ll v[100];

int main() {
  binom_init();
  cin >> N >> A >> B;
  rep(i, 0, N) { cin >> v[i]; }
  sort(v, v + N, greater<ll>());
  ll sum = 0;
  rep(i, 0, A) { sum += v[i]; }
  long double sumd = sum;
  cout << setprecision(20) << fixed << sumd / A << endl;

  ll lastv = v[A - 1];
  ll lastvcnt = 0;
  ll ulastv = 0;
  rep(i, 0, N) {
    if (v[i] > lastv) ++ulastv;
    if (v[i] == lastv) ++lastvcnt;
  }

  ll ans = 0;
  if (ulastv == 0) {
    repe(i, A, B) {
      ll num = i - ulastv;
      ans += binom[lastvcnt][num];
    }
  } else {
    ll num = A - ulastv;
    ans += binom[lastvcnt][num];
  }
  cout << ans << endl;
}

