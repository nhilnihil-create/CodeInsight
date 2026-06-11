#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t x; cin >> x;
  
  int64_t ans = x / 11 * 2;
  
  if (1 <= x % 11 && x % 11 <= 6) ans++;
  
  if (7 <= x % 11) ans += 2;
  
  cout << ans << endl;
  
}