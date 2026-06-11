#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  if (N <= 2) {
    cout << 1 << endl;
    return 0;
  }

  vector<ll> A(N);
  REP(i, N) { cin >> A.at(i); }

  ll ans = 1;
  ll prev_a = A.at(0);
  ll a;
  bool dec = false;
  bool inc = false;
  REPI(i, 1, N) {
    a = A.at(i);

    if (!dec && !inc) {
      if (prev_a != a) {
        if (prev_a < a) {
          inc = true;
        } else {
          dec = true;
        }
      }
      prev_a = a;
      continue;
    }

    if (dec) {
      if (prev_a < a) {
        dec = false;
        ++ans;
      }
      prev_a = a;
      continue;
    }

    if (inc) {
      if (prev_a > a) {
        inc = false;
        ++ans;
      }
      prev_a = a;
      continue;
    }
  }

  cout << ans << endl;

  return 0;
}
