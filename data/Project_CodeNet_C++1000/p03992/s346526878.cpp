#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string str1 = "1234", str2 = " ", str3 = "12345678";
  for (int i = 0; i < 4; i++) {
    str1.at(i) = s.at(i);
  }
  for (int i = 0; i < 8; i++) {
    str3.at(i) = s.at(i + 4);
  }
  cout << str1 << str2 << str3 << endl;
}
