#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout << char(toupper(s1[0])) << char(toupper(s2[0])) << char(toupper(s3[0])) << "\n";
  return 0;
}
