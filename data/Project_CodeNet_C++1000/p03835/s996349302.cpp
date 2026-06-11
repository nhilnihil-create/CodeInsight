#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int k, s;
  cin >> k >> s;

  int result = 0;
  for (int i = max(0, s - 2 * k); i <= k; i++) {
    for (int j = max(0, s - k - i); j <= min(k, s - i); j++) {
      result++;
    }
  }

  cout << result << endl;
  return 0;
}