#include <bits/stdc++.h>

#define MIN(a, b) (a > b ? b : a)

#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long k;
  cin >> k;

  int n = max(2, (int) MIN(k, 50));
  long long ans[n];
  REP(i, n) {
    ans[i] = i;
  }

  long long div = k / n;
  REP(i, n) {
    ans[i] += div;
  }

  int mod = (int) (k % n);
  REP(i, mod) {
    ++ans[n - i - 1];
  }

  cout << n << endl;

  REP(i, n) {
    if (i != 0) {
      cout << ' ';
    }
    cout << ans[i];
  }

  cout << endl;
}
