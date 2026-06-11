#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  set<int> already;
  bool can = false;
  int total = 0;
  for (int i = a; true; i += a) {
    total += a;
    int mod = total % b;
    if (mod == c) {
      can = true;
      break;
    } else {
      if (already.count(mod)) {
        break;
      } else {
        already.insert(mod);
      }
    }
  }

  string ans;
  if (can) {
    ans = "YES";
  } else {
    ans = "NO";
  }
  cout << ans << endl;
  return 0;
}