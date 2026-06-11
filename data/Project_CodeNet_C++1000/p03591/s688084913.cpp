#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;cin >> S;
  int N = S.size();
  string ans = "No";
  if (N >= 4) {
    if (S.at(0) == 'Y' && S.at(1) == 'A' && S.at(2) == 'K' && S.at(3) == 'I') {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}