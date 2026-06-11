#include <iostream>

using namespace std;

int main() {
  long long x, a, b{}, ans{};
  cin >> x >> x;
  while (cin >> a)
    if (b + a > x) ans += b + a - x, b = x - b;
    else b = a;
  cout << ans << endl;
}
