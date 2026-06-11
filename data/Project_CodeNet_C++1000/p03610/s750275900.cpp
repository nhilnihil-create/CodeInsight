#include <iostream>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i+=2) {
    t+=s[i];
  }
  cout << t << endl;
}
