//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  string s;
  cin >> s;
  int ans = 10000;
  rep(i, 26) {
    string t = s;
    int cnt = 0;
    while (true) {
      string u;
      bool flag = true;
      rep(j, t.size()-1) {
        if (t[j] == 'a' + i && t[j+1] == 'a' + i) u.push_back('a' + i);
        else if (t[j] == 'a' + i || t[j+1] == 'a' + i) {
          flag = false;
          u.push_back('a' + i);
        } 
        else {
          flag = false;
          u.push_back(t[j]);
        }
      }
      if (!flag) cnt++;
      else break;
      t = u;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}