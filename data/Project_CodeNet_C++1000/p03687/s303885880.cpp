#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  vector<int>s(N);
  for (int i = 0; i < N; i ++) {
    s[i] = (int)S[i] - (int)'a';
  }
  int ans = 1100;
  vector<int>t(N);
  int si;
  for (int i_ = 0; i_ < 26; i_ ++) {
    for (int i = 0; i < N; i ++) t[i] = s[i];
    si = N;
    while (si > 0) {
      bool ok = true;
      for (int i = 0; i < si; i ++) {
        if (t[i] != i_) ok = false;
      }
      if (ok) {
        break;
      }
      si --;
      for (int i = 0; i < si; i ++) {
        if (t[i + 1] == i_) t[i] = t[i + 1];
      }
    }
    ans = min(ans, N - si);
  }
  cout << ans << endl;
}

