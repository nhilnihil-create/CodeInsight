#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 13;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int bal = 0, min_bal = inf;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      ++bal;
    else
      --bal;
    min_bal = min(bal, min_bal);
  }
  for (int i = 0; i > min_bal; --i) {
    ++bal;
    cout << '(';
  }
  cout << s;
  for (int i = 0; i < bal; ++i)
    cout << ')';
  cout << '\n';
}