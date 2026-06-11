#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int n = 0;
  int s = 0;
  int e = 0;
  int w = 0;
  rep(i, S.size()) {
    if (S[i] == 'N') n++;
    if (S[i] == 'S') s++;
    if (S[i] == 'E') e++;
    if (S[i] == 'W') w++;
  }
  bool ok = true;
  if (n == 0 && s > 0 || n > 0 && s == 0) {
    ok = false;
  }
  if (w == 0 && e > 0 || w > 0 && e == 0) {
    ok = false;
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}