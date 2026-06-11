#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,W,ans; cin >> W >> a >> b;
  if (a >= b + W) ans = a - b - W;
  else if (b >= a + W) ans = b - W - a;
  else ans =0;
  cout << ans << endl;
}
  