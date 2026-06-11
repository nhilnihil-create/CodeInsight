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
  vector<bool> flag(4, false);
  rep(i, s.size()) {
    if (s[i] == 'N') flag[0] = true;
    else if (s[i] == 'S') flag[1] = true;
    else if (s[i] == 'W') flag[2] = true;
    else flag[3] = true;
  }
  if (flag[0] && !flag[1]) {
    cout << "No" << endl;
    return 0;
  }
  else if (!flag[0] && flag[1]) {
    cout << "No" << endl;
    return 0;
  }
  else if (flag[2] && !flag[3]) {
    cout << "No" << endl;
    return 0;
  }
  else if (!flag[2] && flag[3]) {
    cout << "No" << endl;
    return 0;
  }
  else {
    cout << "Yes" << endl;
    return 0;
  }
}