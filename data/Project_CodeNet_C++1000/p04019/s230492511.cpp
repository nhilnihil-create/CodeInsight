#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  sort(S.begin(), S.end());
  S.erase(unique(S.begin(), S.end()), S.end());

  cout << ((S == "ENSW" || S == "NS" || S == "EW") ? "Yes" : "No") << endl;
  return 0;
}