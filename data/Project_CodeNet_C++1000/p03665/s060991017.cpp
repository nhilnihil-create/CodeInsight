#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int N, P;
  cin >> N >> P;

  int A[2] = {0};
  rep(i,0,N-1) {
    int a;
    cin >> a;
    a % 2 == 0 ? A[0]++ : A[1]++;
  }

  ll ans = 0;
  for (int i = 1;; ++i) {
    int times = i * 2 - 1;
    if (A[1] < times) break;

    ll max_denominator = times;
    ll min_numerator = A[1] - times + 1;

    ll numerator = 1, denominator = 1;
    rep(j,0,times-1) {
      ll current = A[1] - j;
      if (current <= max_denominator) break;
      numerator *= current;
    }

    rep(j,0,times-1) {
      ll current = j + 1;
      if (min_numerator <= current) break;
      denominator *= current;
    }

    ans += numerator / denominator;
  }

  ans *= pow(2, A[0]);

  if (P == 0) {
    ll total = pow(2, N);
    ans = total - ans;
  }

  cout << ans << endl;
  return 0;
}
