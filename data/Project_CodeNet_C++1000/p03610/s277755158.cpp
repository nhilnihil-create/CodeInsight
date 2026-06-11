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
  string s;
  cin >> s;

  rep(i, s.size()) {
    if (i % 2 == 0) cout << s[i];
  }
  cout << endl;

  return 0;
}
