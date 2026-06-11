#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  bool e, w, s, n;
  e = false;
  w = false;
  s = false;
  n = false;
  int l = S.length();
  REP(i, l) {
    if (S.at(i) == 'E') {
      e = true;
    } else if (S.at(i) == 'W') {
      w = true;
    } else if (S.at(i) == 'S') {
      s = true;
    } else {
      n = true;
    }
  }

  if (((e && w) || (!e && !w)) && ((n && s) || (!n && !s))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}