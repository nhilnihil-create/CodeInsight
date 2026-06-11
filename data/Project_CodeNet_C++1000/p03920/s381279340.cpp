#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  int cur = 1;
  while (sum <= n) {
    sum += cur++;
  }
  int diff = sum - n;
  int to = diff == 0? cur: cur - 1;
  for (int i = 1; i <= to; ++i) {
    if (i != diff) cout << i << endl;
  }
  return 0;
}