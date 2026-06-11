#include <bits/stdc++.h>
using namespace std;

int main() {
  #define int long long
  string s;
  cin >> s;
  int n = s.size() - 1;
  int res = 0;
  for (int bit = 0; bit < (1<<n); bit++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int si = s.at(i) - '0';
      if ((1<<i) & bit) {
        res = res + 10 * sum + si;
        sum = 0;
      }
      else {
        sum = si + sum * 10;
      }
    }
    res += 10 * sum;
    res += (int)s.at(n) - '0';
  }
  cout << res << endl;
}



