/**
 *    author:  lets
 *    created: 2020-06-07 13:40:22 JST
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string ss;
  cin >> ss;
  while (1) {
    ss.pop_back();
    ss.pop_back();
    int n = (int)ss.size();
    if (ss.substr(0, n / 2) == ss.substr(n / 2, n / 2)) {
      cout << n << '\n';
      return 0;
    }
  }
  return 0;
}