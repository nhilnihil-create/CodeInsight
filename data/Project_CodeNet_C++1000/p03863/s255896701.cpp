#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[0] == s[s.size()-1])
    cout << (s.size() % 2 ? "Second" : "First");
  else
    cout << (s.size() % 2 ? "First" : "Second");
}