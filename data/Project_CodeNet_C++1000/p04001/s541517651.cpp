#include <bits/stdc++.h>
using namespace std;

int main() {
  #define int long long
  string s;
  cin >> s;
  int n = s.size() - 1;
  int res = 0;
  
  for (int bit = 0; bit < (1<<n); bit++) {
    int t = s.at(0) - '0';
    for (int i = 0; i < n; i++) {
      if ((1<<i) & bit) {
        res += t;
        t = s.at(i + 1) - '0';
      }
      else {
        t *= 10;
        t += s.at(i + 1) - '0';
      }
    }
    res += t;
  }
  cout << res << endl;
}
