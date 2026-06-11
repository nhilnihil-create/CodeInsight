#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;

  int ans = 1;
  while (true) {
    if (ans * 2 > n) {
      cout << ans << endl;
      return 0;
    }
    ans *= 2;
  }
}
