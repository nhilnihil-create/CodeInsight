#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size(), ans = 0;
  rep(i, 0, n - 1) {
    if (s[i] != s[i + 1]) {
      ans++;
    }
  }
  cout << ans << endl;
  getchar();
}