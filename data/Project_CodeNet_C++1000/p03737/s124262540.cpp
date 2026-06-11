#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s1,s2,s3;
  cin >> s1 >> s2 >> s3;

  s1 = toupper(s1.at(0));
  s2 = toupper(s2.at(0));
  s3 = toupper(s3.at(0));
  cout << s1 << s2 << s3 << endl;
  return 0;
}
