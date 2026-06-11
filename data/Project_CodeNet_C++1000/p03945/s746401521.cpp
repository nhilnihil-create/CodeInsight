#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s;
  char pre = s[0];
  t.push_back(pre);
  for (int i = 1; i < s.size(); i++) {
    if (pre != s[i]) {
      pre = s[i];
      t.push_back(pre);
    }
  }
  cout << t.size() - 1 << endl;
  return 0;
}
