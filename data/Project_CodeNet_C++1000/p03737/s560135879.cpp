#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string ans = "";
  ans += toupper(s1.at(0));
  ans += toupper(s2.at(0));
  ans += toupper(s3.at(0));
  cout << ans << endl;
}
