#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
  int N, p[1001]{};
  cin >> N;
  for (int i = 2; i <= N; ++i) {
    int I = i;
    for (int j = 2, n = sqrt(I) + 1; I != 1 && j != n; ++j) {
      while (I % j == 0) {
        I /= j;
        ++p[j];
      }
    }
    if (I != 1) ++p[I];
  }

  cout << accumulate(begin(p), end(p), 1ll, [&](ll a, ll x) {
    return a * (x + 1) % MOD;
  }) << endl;
}
