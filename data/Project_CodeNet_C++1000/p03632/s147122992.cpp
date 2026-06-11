#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = max(a, c), y = min(b, d);
  cout << max(0, y - x);
  return 0;
}