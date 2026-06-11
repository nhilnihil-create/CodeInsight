#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  string t = "CODEFESTIVAL2016";
  int ans = 0;
  rep(i, S.size()) {
    if (S[i] != t[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}