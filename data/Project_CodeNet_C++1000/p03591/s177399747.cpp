#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() < 4) cout << "No\n";
  else {
    if (s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}