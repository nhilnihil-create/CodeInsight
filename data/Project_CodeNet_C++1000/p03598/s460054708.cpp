#include <iostream>

using namespace std;

int main() {
  int n, k;
  int x[100];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] < abs(k - x[i])) {
      ans += x[i] * 2;
    } else {
      ans += abs(k - x[i]) * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
