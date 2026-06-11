#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  
  char b, e;
  b = s[0];
  e = s[s.size()-1];
  cout << b << s.size() - 2 << e;
}