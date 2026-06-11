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

  while (N > 0) {
    int n = N % 10;
    if (n == 9) {
      cout << "Yes" << endl;
      return 0;
    }
    N /= 10;
  }

  cout << "No" << endl;

  return 0;
}
