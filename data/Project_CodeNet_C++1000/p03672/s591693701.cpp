#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int h = s.size() / 2;
  int ans;
  for (int i = 1; i < h; ++i) {
    bool same = true;
    rep(j, h - i) if (s[j] != s[j + h - i]) same = false;
    if (same) {
      ans = s.size() - 2 * i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}