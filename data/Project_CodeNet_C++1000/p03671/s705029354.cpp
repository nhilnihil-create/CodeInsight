#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#endif

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(begin(a), end(a));
  cout << a[0] + a[1] << '\n';
  return 0;
}