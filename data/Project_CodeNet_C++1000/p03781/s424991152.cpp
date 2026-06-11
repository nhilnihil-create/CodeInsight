#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;

  int ans = 0;
  for (int i=1; i<=x; i++) {
    if (i * (i + 1) / 2 >= x) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
