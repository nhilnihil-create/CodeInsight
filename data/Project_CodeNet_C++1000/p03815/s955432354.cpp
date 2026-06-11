#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long x;
  cin >> x;
  long long ans = x / 11 * 2;
  x %= 11;
  if (1 <= x && x <= 6)
    ++ans;
  if (7 <= x && x <= 10)
    ans += 2;
  cout << ans << endl;
}
