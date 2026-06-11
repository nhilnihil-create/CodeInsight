#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
  long long a, b, c;
  cin >> a >> b >> c;

  if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }

  if (a == b && b == c) {
    cout << -1 << '\n';
    return 0;
  }

  long long ans = 0;
  while (a % 2 != 1 && b % 2 != 1 && c % 2 != 1) {
    long long tmp1 = a, tmp2 = b, tmp3 = c;
    a = (tmp2 + tmp3) / 2;
    b = (tmp1 + tmp3) / 2;
    c = (tmp1 + tmp2) / 2;
    ans++;
  }
  cout << ans << '\n';
}