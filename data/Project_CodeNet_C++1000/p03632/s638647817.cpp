#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = max(a, c);
  int y = min(b, d);
  if(y-x>0) cout << y-x << endl;
  else cout << 0 << endl;
  return 0;
}