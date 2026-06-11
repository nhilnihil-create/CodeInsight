#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() { 
  int x, y;
  cin >> x >> y;
  int ans = 0;
  if (abs(x) <= abs(y)) {
    ans = abs(y) - abs(x);
    if ((x < 0 && y > 0) || (x >= 0 && y < 0)) ans++;
    if ((x < 0 && y < 0)) ans += 2;
  } else {
    ans = abs(x) - abs(y);
    if ((x > 0 && y <= 0) || (x < 0 && y > 0)) ans++;
    if (x > 0 && y > 0) ans += 2;
  }
  cout << ans << endl;
  return 0;
}