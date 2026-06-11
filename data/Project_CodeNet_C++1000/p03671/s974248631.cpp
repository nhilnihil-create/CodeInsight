#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c; cin >> a >> b >> c;
  int s = a + b;
  int t = a + c;
  int u = b + c;
  if (s <= t && s <= u) cout << s;
  else if (t <= s && t <= u) cout << t;
  else cout << u;
}