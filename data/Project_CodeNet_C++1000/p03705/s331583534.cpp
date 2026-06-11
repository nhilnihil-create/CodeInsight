#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;

  if (B < A) {
    cout << 0 << endl;
    return 0;
  }

  if (A == B) {
    cout << 1 << endl;
    return 0;
  }

  ll l = A * (N - 1) + B;
  ll r = B * (N - 1) + A;
  ll ans = max(r - l + 1, ll(0));
  cout << ans << endl;
  return 0;
}
