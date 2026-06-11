#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s[4] = {"dream","dreamer","erase","eraser"};

int main() {
  string t;
  cin >> t;
  int now = t.size();
  while (1) {
    bool f = 0;
    for (int i = 0; i < 4; i++) {
      int bf = now - s[i].size();
      if (bf < 0) continue;
      if (s[i] == t.substr(bf,s[i].size())) {
        // cout << s[i] << " " << t.substr(bf,s[i].size()) << endl;
        now -= s[i].size();
        f = 1;
        break;
      }
    }
    if (!f) break;
  }
  // cout << now << endl;
  if (now != 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/