#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  string ans = "No";
  for (int i = 0; i <s.size(); i++) {
    if (s.at(i) == '9') {
      ans = "Yes";
    }
  }
  cout << ans << endl;
}
  