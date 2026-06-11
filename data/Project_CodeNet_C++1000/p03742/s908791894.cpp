#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long x, y;
  cin >> x >> y;
  cout << (abs(x - y) > 1 ? "Alice" : "Brown") << endl;
  return 0;	
}