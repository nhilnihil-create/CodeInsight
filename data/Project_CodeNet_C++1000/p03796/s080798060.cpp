#include <iostream>

using namespace std;

const int m = 1000000000 + 7;

int main() {
  int n;
  cin >> n;
  long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
    ans %= m;
  }
  cout << ans << endl;
  return 0;
}
