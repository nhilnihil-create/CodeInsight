#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  string s;
  cin >> s;

  int ans = 0;
  int n = s.length();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1]) ans++;
  }
  cout << ans << endl;
}
