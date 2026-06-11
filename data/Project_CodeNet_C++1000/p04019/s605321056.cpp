#include <iostream>

using namespace std;

int main() {
  string S;
  cin >> S;
  bool n = S.find('N') != S.npos;
  bool e = S.find('E') != S.npos;
  bool w = S.find('W') != S.npos;
  bool s = S.find('S') != S.npos;

  cout << (n == s && w == e ? "Yes" : "No") << endl;
  return 0;
}
