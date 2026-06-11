#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, ans;
  cin >> a >> b >> c >> d;
  
  if (a < c) {
    if (c < b) {
      if (b < d) ans = b - c;
      else ans = d - c;
    } else ans = 0;
  } else {
    if (a < d) {
      if (d < b) ans = d - a;
      else ans = b - a;
    } else ans = 0;
  }
  
  cout << ans << endl;
}