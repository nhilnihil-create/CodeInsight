#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll X, A, B;
  cin >> X >> A >> B;
  if (B <= A) {
    cout << "delicious" << endl;
  } else if (B - A > X) {
    cout << "dangerous" << endl;
  } else {
    cout << "safe" << endl;
  }

  return 0;
}
