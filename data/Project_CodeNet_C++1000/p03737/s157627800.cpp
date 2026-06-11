#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  cout << (char)(s1[0] - 'a' + 'A') << (char)(s2[0] - 'a' + 'A') << (char)(s3[0] - 'a' + 'A') << endl;

  return 0;
}
