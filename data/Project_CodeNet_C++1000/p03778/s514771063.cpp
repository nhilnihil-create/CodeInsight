#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int w, a, b;
  cin >> w >> a >> b;

  if (a < (b + w)) {
    if (a + w < b) {
      cout << b - (a + w) << endl;
    } else {
      cout << 0 << endl;
    }
  } else {
    if (b + w < a) {
      cout << a - (b + w) << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}
