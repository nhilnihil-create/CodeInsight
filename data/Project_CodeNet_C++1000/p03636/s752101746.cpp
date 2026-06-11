#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string s;
  cin >> s;
  
  int number = 0;
  number = s.length();
  cout << s[0] << number - 2 << s[number - 1] << endl;
  return 0;
}