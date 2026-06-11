#include <iostream>
using namespace std;

int main() {
  int n, a[100001] = {}, cnt = 0, t;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    a[i] = t;
    if (a[t] == i) ++cnt;
  }
  cout << cnt << '\n';
  return 0;
}