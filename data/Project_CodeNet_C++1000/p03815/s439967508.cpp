#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  if (N <= 6) return cout << 1 << "\n", 0;
  long ans = N / 11;
  ans *= 2;
  N %= 11;
  cout << ans + (N + 6 - 1) / 6 << "\n";
}