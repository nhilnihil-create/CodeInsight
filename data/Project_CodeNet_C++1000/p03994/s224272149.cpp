#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  string s;
  int k;
  cin >> s >> k;

  string ans = "";

  const char ch = '{';

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' && i != s.size() - 1) {
      ans += 'a';
    } else if (ch - s[i] <= k && i != s.size() - 1) {
      ans += 'a';
      k -= (ch - s[i]);
    } else {
      if (i != s.size() - 1)
        ans += s[i];
      else {
        // cout << "fejoofewij" << endl;
        // cout << k << endl;
        ans += (s[i] + k % 26) > 'z' ? s[i] + k % 26 - 'z' + 'a' - 1
                                     : s[i] + k % 26;
      }
    }
  }
  cout << ans << endl;

  // cout << k << endl;
}