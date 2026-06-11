#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int x, y;
  cin >> x >> y;
  
  if (x == y) cout << "0\n";
  else if (x < y) cout << min(y - x, abs(y + x) + 1) << '\n';
  else cout << min(abs(x + y) + 1, x - y + 2) << '\n';
}