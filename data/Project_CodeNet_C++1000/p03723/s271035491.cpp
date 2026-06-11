#include <bits/stdc++.h>
using namespace std;

vector<long long> a;

int main() {
  a.resize(3);
  for (int i = 0; i < 3; ++i) cin >> a[i];
  for (int i = 0; i < 1000000; ++i) {
    if (a[0] % 2 || a[1] % 2 || a[2] % 2) {
      cout << i << endl;
      return 0;
    }
    long long x = a[0] / 2, y = a[1] / 2, z = a[2] / 2;
    a[0] = x + y;
    a[1] = x + z;
    a[2] = y + z;
  }
  cout << -1 << endl;
  return 0;
}
