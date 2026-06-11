#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  string s;
  cin >> s;

  string ans = "";
  rep(i,s.size()) {
    if (s[i] == '0') ans += '0';
    else if (s[i] == '1') ans += '1';
    else {
      if (ans.size() == 0) continue;
      else ans = ans.substr(0,ans.size()-1);
    }
  }
  cout << ans << endl;
  return 0;
}