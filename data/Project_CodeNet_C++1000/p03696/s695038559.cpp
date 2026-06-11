#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int need_right = 0, need_left = 0;

  rep(i, s.size()) {
    if (s[i] == '(')
      need_right++;
    else {
      if (!need_right)
        need_left++;
      else
        need_right--;
    }
  }
  rep(i, need_left) cout << "(";
  cout << s;
  rep(i, need_right) cout << ")";
  cout << endl;
}
