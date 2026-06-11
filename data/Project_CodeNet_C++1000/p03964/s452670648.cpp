#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, T, A, sum, t, a, mag;
  cin >> N >> T >> A;
  sum = T + A;
  while (cin >> t >> a)
    mag = max((T + t - 1) / t, (A + a - 1) / a), t *= mag, a *= mag, sum = t + a, T = t, A = a;
  cout << sum << "\n";
}