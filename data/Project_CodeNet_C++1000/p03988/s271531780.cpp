#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<int> x(n);
  int minimum = 1e9, maximum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    x.at(a)++;
    minimum = min(minimum, a);
    maximum = max(maximum, a);
  }
  
  bool flag = true;
  if (maximum % 2 == 0) {
    if (minimum != maximum / 2 || x.at(minimum) != 1) flag = false;
    for (int i = minimum + 1; i <= maximum; i++) {
      if (x.at(i) <= 1) flag = false;
    }
    if (flag) cout << "Possible\n";
    else cout << "Impossible\n";
  }
  else {
    if (minimum != maximum / 2 + 1 || x.at(minimum) != 2) flag = false;
    for (int i = minimum + 1; i <= maximum; i++) {
      if (x.at(i) <= 1) flag = false;
    }
    if (flag) cout << "Possible\n";
    else cout << "Impossible\n";
  }
}