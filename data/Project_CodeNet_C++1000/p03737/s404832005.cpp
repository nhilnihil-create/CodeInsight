#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string ans;
  ans += (char)((int)s1[0] + 'A' - 'a');
  ans += (char)((int)s2[0] + 'A' - 'a');
  ans += (char)((int)s3[0] + 'A' - 'a');
  cout << ans << endl;
  return 0;
}