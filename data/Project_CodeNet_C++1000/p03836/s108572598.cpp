#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  string ans = "D";
  for (int i = 0; i < (tx - sx) + 1; i++) ans += "R";
  for (int i = 0; i < (ty - sy) + 1; i++) ans += "U";
  ans += "LU";
  for (int i = 0; i < (tx - sx) + 1; i++) ans += "L";
  for (int i = 0; i < (ty - sy) + 1; i++) ans += "D";
  ans += "R";
  
  for (int i = 0; i < (ty - sy); i++) ans += "U";
  for (int i = 0; i < (tx - sx); i++) ans += "R";
  for (int i = 0; i < (ty - sy); i++) ans += "D";
  for (int i = 0; i < (tx - sx); i++) ans += "L";
  cout << ans << '\n';
  return 0;
}
