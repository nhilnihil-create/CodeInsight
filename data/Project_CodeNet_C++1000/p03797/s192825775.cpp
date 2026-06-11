#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  long long ans = min(n, m / 2);
  long long use = min(n, m / 2);
  n -= use;
  m -= use * 2;
  ans += m / 4;
  cout << ans << endl;
  return 0;
}