#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i - 1] != s[i]) {
      cnt++;
    }
  }

  cout << cnt << endl;
}
