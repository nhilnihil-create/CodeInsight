#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  //
  string S;
  string T = "CODEFESTIVAL2016";
  cin >> S;
  int ans = 0;
  rep(i, S.size()) {
    if (S.at(i) != T.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}