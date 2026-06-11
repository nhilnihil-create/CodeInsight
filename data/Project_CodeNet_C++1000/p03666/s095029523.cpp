#include <iostream>
#include <vector>
using namespace std;

int main() {
  long n, a, b, c, d;
  cin >> n;
  cin >> a >> b >> c >> d;
  b = abs(a - b);
  a = 0;
  string ans = "NO";
  long m = n - 1;
  for (long i = 0; i <= m; i++) {
    long max = d * i - c * (m - i);
    long min = c * i - d * (m - i);
    if (min <= b && b <= max) {
      ans = "YES";
    }
  }
  cout << ans << endl;
  return 0;
}
