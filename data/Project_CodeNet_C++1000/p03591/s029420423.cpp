#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  string ans = "No";
  if (str.size() >= 4) {
    if (str.at(0) == 'Y') {
      if (str.at(1) == 'A') {
        if (str.at(2) == 'K') {
          if (str.at(3) == 'I') {
          ans = "Yes";
          }
        }
      }
    }
  }
  cout << ans << endl;
}
