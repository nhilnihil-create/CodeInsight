#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[0] != s.back() && s.length()%2) {
    cout << "First";
  } else if (s[0] != s.back()) {
    cout << "Second";
  } else if (s.length()%2) {
    cout << "Second";
  } else {
    cout << "First";
  }
}