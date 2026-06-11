#include <iostream>

using namespace std;

int main() {
  int k, s;
  cin >> k >> s;
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= k; j++) {
      int d = s - i - j;
      if (d >= 0 && d <= k) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
