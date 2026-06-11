#include <iostream>

using namespace std;

int main() {
  int N, l, r, ans{};
  cin >> N;
  while (cin >> l >> r) {
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
