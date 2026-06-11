#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  vector<string> t(4);
  t[0] = "dream";
  t[1] = "dreamer";
  t[2] = "erase";
  t[3] = "eraser";

  bool flag = true;
  int cur = n - 1;
  while(cur >= 0) {
    bool ok = false;
    for (int i = 0; i < 4; i++) {
      int m = t[i].size();
      if(cur - m + 1 < 0) continue;
      string tmp = s.substr(cur - m + 1, m);
      if(tmp == t[i]) {
        cur -= m;
        ok = true;
        break;
      }
    }
    if(!ok) {
      flag = false;
      break;
    }
  }

  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}