#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  if(n % 2 == 0 ^ s.front() == s.back()) {
    cout << "Second" << '\n';
  } else {
    cout << "First" << '\n';
  }
}