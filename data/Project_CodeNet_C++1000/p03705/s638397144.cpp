#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B;
  cin >> N >> A >> B;
  ll ans = 0;
  if (A <= B) {
    if (N == 1) {
      if (A == B) {
        ans = 1;
      }
    } else {
      ll n2 = N - 2;
      ans = B * n2 - A * n2 + 1;
    }
  }

  cout << ans << endl;

  return 0;
}
