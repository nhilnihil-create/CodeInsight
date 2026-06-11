#include <bits/stdc++.h>
using namespace std;

int main() {
string s1, s2, s3;
  cin >>s1>>s2>>s3;
  char c1, c2, c3;
  c1 = s1.at(0);
  c2 = s2.at(0);
  c3 = s3.at(0);
  char dif = 'A'-'a';
  cout << (char)(c1+dif) << (char)(c2+dif) << (char)(c3+dif) << endl;
}
