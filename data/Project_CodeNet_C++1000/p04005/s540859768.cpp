#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A, B, C;
  cin >> A >> B >> C;

  ll longest_edge = max(max(A, B), C);
  if (longest_edge % 2 == 0) {
    cout << 0 << endl;
  } else {
    if (longest_edge == A) {
      cout << B * C << endl;
    } else if (longest_edge == B) {
      cout << A * C << endl;
    } else {
      cout << A * B << endl;
    }
  }

  return 0;
}
