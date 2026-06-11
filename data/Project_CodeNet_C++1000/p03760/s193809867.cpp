#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string o, e;
  cin >> o >> e;

  string res = "";
  for (int i = 0; i < o.size(); i++) {
    res.push_back(o.at(i));
    if (i < e.size()) {
      res.push_back(e.at(i));
    }
  }
  cout << res << endl;
  return 0;
}