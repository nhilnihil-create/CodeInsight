#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
char func(char cur, char nbr, char info) {
  if (cur == 'S') {
    if (info == 'o') {
      return nbr;
    } else {
      return 'W' + 'S' - nbr;
    }
  } else {
    if (info == 'o') {
      return 'W' + 'S' - nbr;
    } else {
      return nbr;
    }
  }
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string s, t = "SW";
  cin >> s;
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      vector<char> test(n + 1);
      test[0] = t[x];
      test[1] = t[y];
      for (int i = 1; i < n; i++) {
        test[i + 1] = func(test[i], test[i - 1], s[i]);
      }
      if (func(test[0], test[1], s[0]) != test[n - 1] || test[n] != test[0]) continue;
      for (int i = 0; i < n; i++) {
        cout << test[i];
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;	
}