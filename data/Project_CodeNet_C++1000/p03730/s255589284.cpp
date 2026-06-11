#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int g = __gcd(a, b);
  int d = b / g;
  // [0, d)があまりの周期
  // cがこの余りの中に出てくるか判定
  // 0, gcd(a, b), gcd(a, b) * 2 ~ gcd(a, b) * (d - 1)

  if (c % g != 0 || c / g >= d)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
