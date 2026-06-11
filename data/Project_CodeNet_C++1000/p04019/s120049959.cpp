#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  bool n = false;
  bool s = false;
  bool e = false;
  bool w = false;
  rep(i, S.size()) {
    if (S[i] == 'N') n = true;
    if (S[i] == 'S') s = true;
    if (S[i] == 'E') e = true;
    if (S[i] == 'W') w = true;
  }
  if (n == s && w == e) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}