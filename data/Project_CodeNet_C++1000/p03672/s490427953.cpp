#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, ss;
  cin >> s;
  for (int i = s.size() - 2; i >= 2; i -= 2) {
    ss = s.substr(0, i);
    if (ss.substr(0, ss.size() / 2) ==
        ss.substr(ss.size() / 2, ss.size() / 2)) {
      cout << ss.size() << endl;
      return 0;
    }
  }
  return 0;
}
