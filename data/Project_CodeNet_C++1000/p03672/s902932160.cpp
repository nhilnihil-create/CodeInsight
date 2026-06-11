#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int res = 0;
  for (int i = 2; i < N; i += 2) {
    string T = S.substr(0, N-i);
    string zen = T.substr(0, T.size()/2);
    if (T == zen + zen) {
      res = N-i;
      break;
    }
  }
  cout << res << endl;
}