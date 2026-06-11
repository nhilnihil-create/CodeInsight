#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N == 1) return cout << 1 << "\n", 0;
  int ans = 2;
  while (ans * 2 <= N) ans *= 2;
  cout << ans << "\n";
}