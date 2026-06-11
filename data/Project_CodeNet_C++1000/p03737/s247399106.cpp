#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1 = toupper(s1[0]);
  s2 = toupper(s2[0]);
  s3 = toupper(s3[0]);
  string sum = s1+s2+s3;
  cout << sum << endl;
  return 0;
}