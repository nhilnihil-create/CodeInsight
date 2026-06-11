#include <bits/stdc++.h>
using namespace std;

int main() {
  long W, a, b, ans = 0;
  cin >> W >> a >> b;
  
  if (a <= b) ans = b - a - W;
  else ans = a - b - W;
  
  if (ans < 0) ans = 0;
  
  cout << ans << endl;
}