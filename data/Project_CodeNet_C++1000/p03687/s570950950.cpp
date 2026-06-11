#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

bool ok (string s) {
  char c = s[0];
  rep(i,1,s.size()-1)
    if (s[i] != c) return false;

  return true;
}

int main() {
  string s;
  cin >> s;

  int ans = 1001001001;
  for (char c = 'a'; c <= 'z'; c++) {
    string new_s = s;
    int cnt = 0;
    while (!ok(new_s)) {
      rep(i,0,new_s.size()-2) {
        if (new_s[i] == c || new_s[i+1] == c) {
          new_s[i] = c;
        }
      }
      new_s.pop_back();
      cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}
