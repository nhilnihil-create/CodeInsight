#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1[0] = toupper(s1[0]);
  s2[0] = toupper(s2[0]);
  s3[0] = toupper(s3[0]);
  cout << s1[0] << s2[0] << s3[0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
