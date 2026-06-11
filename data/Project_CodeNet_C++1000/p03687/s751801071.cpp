#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int ans = (int)1e9;
  for (char c = 'a'; c <= 'z'; c++) {
    string t = s;
    if (t.find(c) != string::npos) {
      int cnt = 0;
      int mx = 0;
      for (int i = 0; i < t.size(); i++) {
        if (t[i] == c) {
          mx = max(cnt, mx);
          cnt = 0;
        } else {
          cnt++;
        }
      }
      mx = max(cnt, mx);
      ans = min(ans, mx);
    }
  }

  cout << ans << endl;
  return 0;
}