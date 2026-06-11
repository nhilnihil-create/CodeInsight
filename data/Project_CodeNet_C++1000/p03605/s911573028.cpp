#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string ans = "No";
  if (s[0] == '9' || s[1] == '9') ans = "Yes";
  cout << ans << endl;
}