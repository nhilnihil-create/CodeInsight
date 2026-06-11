#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string s;
 
  cin >> s;
  
  s[5]=' ',s[13]=' ';
  
  for (int i = 0; i < s.size(); i++) {
      if ( s.at(i) == ',' ) {
        s.at(i) = ' ';
      }  
  }
  
  cout << s << endl;
}