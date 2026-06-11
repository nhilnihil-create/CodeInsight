#include <bits/stdc++.h>

using namespace std;

const string T = "CODEFESTIVAL2016";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string S;
  cin >> S;
  int cnt = 0;
  for (int i = 0; i < (int)T.size(); i++) {
    if (S[i] != T[i]) cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
