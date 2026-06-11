#include <iostream>

using namespace std;

int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  k = min(n, k);
  int ans = x * k + y * (n - k);
  cout << ans << endl;
  return 0;
}
