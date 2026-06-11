#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;cin >> S;string correct = "CODEFESTIVAL2016";
  int ans = 0;
  for (int i = 0; i < 16; i++) {
    if (S.at(i) != correct.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}