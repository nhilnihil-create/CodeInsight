#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  cout << ((s[0] == s[s.size() - 1]) ^ (s.size() % 2) ? "First" : "Second") << endl;
}
