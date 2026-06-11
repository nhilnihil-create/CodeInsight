#include <bits/stdc++.h>
using namespace std;

long f(long x, long y) {
  return max(to_string(x).size(), to_string(y).size());
}

int main() {
  long N;
  cin >> N;
  long ans = 1e9;
  for (long i = 1; i * i <= N; i++) {
    if (N % i == 0) ans = min(ans, f(i, N / i));
  }
  cout << ans << "\n";
}