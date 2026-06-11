#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;

ll signCheck(ll A1, ll A2) {
  if (A2 - A1 > 0) {
    return 1;
  } else  if (A2 - A1 < 0) {
    return -1;
  } else {
    return 0;
  }
}


int main(void) {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll oldSign = 0;
  ll ans = 1;
  ll sign = 0;
  oldSign = signCheck(A[0], A[1]);

  for (int i = 2; i < N; ++i) {
    sign = signCheck(A[i - 1], A[i]);
    if (sign == 0) continue;
    if (oldSign == 0) {
      oldSign = sign;
      continue;
    }
    if (oldSign != sign) {
      ans++;
      oldSign = 0;
    }
  }

  cout << ans << endl;

  
  return 0;
}