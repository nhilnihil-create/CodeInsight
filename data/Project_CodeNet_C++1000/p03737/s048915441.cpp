#include <iostream>

using namespace std;

int main() {
  string s, t, u;
  cin >> s >> t >> u;
  int d = 'a' - 'A';
  cout << (char)(s[0] - d);
  cout << (char)(t[0] - d);
  cout << (char)(u[0] - d) << endl;
  return 0;
}
