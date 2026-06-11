#include <bits/stdc++.h>

using namespace std;

template <class T> inline bool chmax(T &a, T b) { /* {{{ */
  if (a < b) {
    a = b;
    return true;
  }
  return false;
} /* }}} */

int main() {
  int N;
  string S;
  cin >> N >> S;
  int cnt = 0;
  int pre = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      cnt++;
    } else {
      cnt--;
      chmax(pre, -cnt);
    }
  }

  for (int i = 0; i < pre; i++) {
    cout << '(';
  }
  cout << S;
  for (int i = 0; i < cnt + pre; i++) {
    cout << ')';
  }
  cout << endl;

  return 0;
}
/* vim:set fdm=marker: */
