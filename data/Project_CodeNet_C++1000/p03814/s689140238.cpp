#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int st, la;
string s;

int main() {
  cin >> s;
  st = -1;
  rep (i, s.size()) {
    if (st == -1 && s[i] == 'A') st = i;
    if (s[i] == 'Z') la = i;
  }
  cout << la - st + 1 << endl;
  return 0;
}
