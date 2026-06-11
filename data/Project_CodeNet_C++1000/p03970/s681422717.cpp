#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string t = "CODEFESTIVAL2016";
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) ans++;
  }
  cout << ans << '\n';
  return 0;
}
