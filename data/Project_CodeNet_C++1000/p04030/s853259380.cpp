#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  string a = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'B') {
      if (a != "") a.pop_back();
    } else {
      a += s[i];
    }
  }
  cout << a;
  
  return 0;
}