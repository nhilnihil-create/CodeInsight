#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = 0;
  rep(i, (int)s.size() - 1) {
    if (s[i] ^ s[i + 1]) ans++;
  }
  cout << ans;
  return 0;
}