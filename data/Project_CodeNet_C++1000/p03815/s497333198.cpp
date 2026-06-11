#include <iostream>

using namespace std;

int main() {
  long long x;
  cin >> x;

  long long cnt = x / 11 * 2;
  x %= 11;
  if (x > 0) ++cnt;
  if (x > 6) ++cnt;

  cout << cnt << endl;
}
