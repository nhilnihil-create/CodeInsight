#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<long long> ts(n);
  for (long long &t : ts) cin >> t;

  long long result = ts[0];
  long long t0, t1, t2;
  for (int i = 0; i < n; ++i) {
    t0 = __gcd(result, ts[i]);
    t1 = result / t0;
    t2 = ts[i] / t0;
    result = t0 * t1 * t2;
  }

  cout << result << endl;
  return 0;
}