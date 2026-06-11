#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<int> v(26, 0);
  rep(i, s.size()) {
    v[s.at(i) - 'a']++;
  }
  bool ok = true;
  rep(i, v.size()) {
    if (v[i] % 2 != 0) {
      ok = false;
    }
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
