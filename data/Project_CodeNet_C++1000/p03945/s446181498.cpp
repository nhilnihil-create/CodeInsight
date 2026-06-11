#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int len = (int)s.size();
  
  int res = 0;
  for (int i=1; i<len; ++i) {
    if (s.at(i) != s.at(i-1)) ++res;
  }
  cout << res << endl;
  return 0;
}
